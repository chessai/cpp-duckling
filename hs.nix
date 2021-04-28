with (import <nixpkgs> {});

pkgs.haskell.packages.ghc8104.ghcWithPackages (hp: with hp; [
  base
  bytestring
  duckling
  text
])
