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
            texliveFull

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
          buildInputs = with pkgs; [doxygen_gui];
          buildPhase = ''
            doxygen
          '';
          installPhase = ''
            mkdir -p $out
            cp -r doc/html $out

            mkdir -p $out/usr/share
            cp -r doc/man $out/usr/share
          '';
        };
      };
    });
}
