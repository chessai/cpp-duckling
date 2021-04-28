{-# LANGUAGE ForeignFunctionInterface #-}

module CDuckling
  (
  ) where

import Foreign
import Foreign.C.Types
import Foreign.C.String
import Foreign.Ptr
import Foreign.StablePtr

import Duckling.Core
import Duckling.Types
import Duckling.Resolve
import Duckling.Dimensions.Types

cEnumToEnum :: Enum a => Ptr CInt -> IO a
cEnumToEnum ptr = do
  a <- peek ptr
  pure $ toEnum . fromIntegral $ a

cLangToLang :: Ptr CInt -> IO Lang
cLangToLang = cEnumToEnum

cRegionToRegion :: Ptr CInt -> IO Region
cRegionToRegion = cEnumToEnum

cEnumToDimension :: Ptr CInt -> IO (Seal Dimension)
cEnumToDimension ptr = do
  i <- peek ptr
  pure $ case i of
    0 -> Seal AmountOfMoney
    1 -> Seal CreditCardNumber
    2 -> Seal Distance
    3 -> Seal Duration
    4 -> Seal Email
    5 -> Seal Numeral
    6 -> Seal Ordinal
    7 -> Seal PhoneNumber
    8 -> Seal Quantity
    9 -> Seal Temperature
    10 -> Seal Time
    11 -> Seal TimeGrain
    12 -> Seal Url
    13 -> Seal Volume
    _  -> error "cduckling: cEnumToDimension: out of bounds"

cLocaleToLocale :: Ptr Locale -> IO Locale
cLocaleToLocale ptr = do
  lang <- cLangToLang (castPtr ptr)
  let region_ptr = castPtr ptr `plusPtr` 8
  if region_ptr == nullPtr
  then pure $ makeLocale lang Nothing
  else do
    region <- cRegionToRegion region_ptr
    pure $ makeLocale lang (Just region)

cOptionsToOptions :: Ptr Options -> IO Options
cOptionsToOptions ptr = Options <$> peek (castPtr ptr)

cDimensionsToDimensions :: Ptr (Seal Dimension) -> IO [Seal Dimension]
cDimensionsToDimensions ptr = go (castPtr ptr) []
  where
    go p dims = do
      if ptr == nullPtr
      then pure dims
      else do
        dim <- cEnumToDimension p
        go (p `plusPtr` 8) (dim : dims)

{-
foreign export ccall run :: ()
  => CString
  -> Ptr Locale
  -> Ptr Options
  -> Ptr Dimension -- ^ array of dimensions
  -> IO CString
run text locale_ptr options_ptr dimensions_ptr = do
  locale <- cLocaleToLocale locale_ptr
  options <- cOptionsToOptions options_ptr
  dimensions <- cDimensionsToDimensions dimensions_ptr
  newCString ""
-}
