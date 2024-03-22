{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = {self, ...} @ inputs:
    inputs.utils.lib.eachDefaultSystem (system: let
      pkgs = inputs.nixpkgs.legacyPackages.${system};
    in rec {
      devShells.default = pkgs.mkShell {
        packages =
          (with pkgs; [
            doxygen_gui

            criterion
            gtest
            gcovr

            valgrind
            gdb
            bear
          ])
          ++ (
            builtins.concatMap
            (p: p.buildInputs ++ p.nativeBuildInputs)
            (builtins.attrValues packages)
          );
      };

      formatter = pkgs.alejandra;

      packages = {
        default = packages.arcade;
        arcade = pkgs.stdenv.mkDerivation rec {
          name = "arcade";
          src = ./.;
          nativeBuildInputs = with pkgs; [cmake];
          installPhase = ''
            mkdir -p $out/bin
            cp ${name} $out/bin
          '';
        };

        doc = pkgs.stdenv.mkDerivation {
          name = "doc";
          src = ./.;
          buildInputs =
            packages.arcade.nativeBuildInputs
            ++ (with pkgs; [doxygen texliveFull]);

          buildPhase = ''
            cmake .
            make doc
          '';
          installPhase = ''
            mkdir -p $out/var/www
            cp -r doc/html $out/var/www
          '';
        };
      };
    });
}
