GHC_INCLUDE_PATH=$$(nix-build hs.nix)/lib/ghc-8.10.4/include

build:
	g++ -Wall -std=c++17 -I $(GHC_INCLUDE_PATH) duckling.cpp -c -o duckling.o
	ghc src/CDuckling.hs
