{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        cc = pkgs.gcc12;
      in
      {
        devShells.default = pkgs.mkShell {
          packages = [ cc ] ++ (with pkgs; [
            libcxx
            gnumake
            criterion
            gcovr
            ltrace
            valgrind
            bear
            gdb
            gtest
            cmake
            ninja
            doxygen_gui
          ]);
        };

        formatter = pkgs.nixpkgs-fmt;

        packages = {
          doc = pkgs.stdenv.mkDerivation {
            name = "doc";
            src = ./.;
            buildInputs = [ pkgs.doxygen ];
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
