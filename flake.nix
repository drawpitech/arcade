{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = {self, ...} @ inputs:
    inputs.utils.lib.eachDefaultSystem (system: let
      pkgs = inputs.nixpkgs.legacyPackages.${system};

      buildArcade = target:
        pkgs.stdenv.mkDerivation {
          name = "arcade";
          src = ./.;
          nativeBuildInputs = with pkgs; [
            cmake
            pkg-config
            ncurses
            sfml
            openal
            libvorbis
            flac
            SDL2
            SDL2_image
            libtiff
            libwebp
            SDL2_ttf
            pcre2.dev
            xdot
          ];
          enableParallelBuilding = true;
          buildPhase = ''
            cmake -DCMAKE_BUILD_TYPE=${target} -S ${./.} -B .build
            make -C .build -j
          '';
          installPhase = ''
            cd .build

            mkdir -p $out/bin
            cp arcade $out/bin

            mkdir -p $out/var/lib
            cp lib/*.so $out/var/lib
          '';
        };
    in rec {
      devShells.default = pkgs.mkShell {
        packages =
          (with pkgs; [
            doxygen_gui
            act

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
        arcade = buildArcade "release";
        debug = buildArcade "debug";

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
