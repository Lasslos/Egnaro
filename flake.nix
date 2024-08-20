{
  description = "ESP32 Enviroment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };
      in {
        # nix develop <flake-ref>#<name>
        # -- 
        # $ nix develop <flake-ref>#first
        devShell = with pkgs; mkShell rec {
          buildInputs = [
            platformio
            python3
          ];
        };
      }
    );
}
