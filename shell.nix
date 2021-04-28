with (import <nixpkgs> {});

let
  hs = import ./hs.nix;
pkgs.mkShell {
  name = "dev-env";
  buildInputs = with pkgs; [
    hs
    gcc
    gnumake
  ];
}
