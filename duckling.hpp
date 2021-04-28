#include <stdbool.h>
#include <string>

#include "HsFFI.h"

bool ducklingInit() {
  int argc = 0;
  char *argv[] = { NULL };
  char **pargv = argv;
  hs_init(&argc, &pargv);
  return HS_BOOL_TRUE;
}

void ducklingExit() {
  hs_exit();
}

enum class Lang {
    AF,
    AR,
    BG,
    BN,
    CA,
    CS,
    DA,
    DE,
    EL,
    EN,
    ES,
    ET,
    FA,
    FI,
    FR,
    GA,
    HE,
    HI,
    HR,
    HU,
    ID,
    IS,
    IT,
    JA,
    KA,
    KN,
    KM,
    KO,
    LO,
    ML,
    MN,
    MY,
    NB,
    NE,
    NL,
    PL,
    PT,
    RO,
    RU,
    SK,
    SV,
    SW,
    TA,
    TE,
    TH,
    TR,
    UK,
    VI,
    ZH
};

enum class Region {
    AR,
    AU,
    BE,
    BZ,
    CA,
    CL,
    CN,
    CO,
    EG,
    ES,
    GB,
    HK,
    IE,
    IN,
    JM,
    MN,
    MX,
    MO,
    NL,
    NZ,
    PE,
    PH,
    TT,
    TW,
    US,
    VE,
};

struct Locale {
    Lang lang;
    Region region;
};

enum class Dimension {
    AmountOfMoney,
    CreditCardNumber,
    Distance,
    Duration,
    Email,
    Numeral,
    Ordinal,
    PhoneNumber,
    Quantity,
    Temperature,
    Time,
    TimeGrain,
    Url,
    Volume
};

struct Options {
    bool withLatent;
};

std::string run (
    std::string text,
    Locale locale,
    Options options,
    Dimension dimensions[]
);

//char *ducklingParseText(char *text, DucklingTimePtr time, DucklingLocalePtr locale, bool latent, DucklingDimensionPtr dimensions[]);

//// Initializion/Shutdown

//bool ducklingInit();
//void ducklingExit();

//void ducklingFreeString(char *string);

//void ducklingFreeObject(void *object);

// Dimension

//typedef void *DucklingDimensionPtr;

//DucklingDimensionPtr ducklingParseDimension(char *dimension);
//char *ducklingGetDimensionName(DucklingDimensionPtr dimension);
//DucklingDimensionPtr ducklingGetBuiltinDimensionCreditCardNumber();
//DucklingDimensionPtr ducklingGetBuiltinDimensionDistance();
//DucklingDimensionPtr ducklingGetBuiltinDimensionDuration();
//DucklingDimensionPtr ducklingGetBuiltinDimensionEmail();
//DucklingDimensionPtr ducklingGetBuiltinDimensionAmountOfMoney();
//DucklingDimensionPtr ducklingGetBuiltinDimensionNumeral();
//DucklingDimensionPtr ducklingGetBuiltinDimensionOrdinal();
//DucklingDimensionPtr ducklingGetBuiltinDimensionPhoneNumber();
//DucklingDimensionPtr ducklingGetBuiltinDimensionQuantity();
//DucklingDimensionPtr ducklingGetBuiltinDimensionTemperature();
//DucklingDimensionPtr ducklingGetBuiltinDimensionTime();
//DucklingDimensionPtr ducklingGetBuiltinDimensionUrl();
//DucklingDimensionPtr ducklingGetBuiltinDimensionVolume();


// Lang

//typedef void *DucklingLangPtr;

//DucklingLangPtr ducklingParseLang(char *lang);


// Region

//typedef void *DucklingRegionPtr;

//DucklingRegionPtr ducklingParseRegion(char *region);


// Locale

//typedef void *DucklingLocalePtr;

//DucklingLocalePtr ducklingMakeLocale(DucklingLangPtr lang, DucklingRegionPtr region);


// TimeZoneSeriesMap

//typedef void *DucklingTimeZoneSeriesMapPtr;

//DucklingTimeZoneSeriesMapPtr ducklingLoadTimeZoneSeriesMap(char *base);


// TimeZoneSeries

//typedef void *DucklingTimeZoneSeriesPtr;

//DucklingTimeZoneSeriesPtr ducklingGetTimeZoneSeries(DucklingTimeZoneSeriesMapPtr timeZoneSeriesMap, char *name);


// Time

//typedef void *DucklingTimePtr;

//DucklingTimePtr ducklingGetCurrentTime(DucklingTimeZoneSeriesPtr timeZoneSeries);
//DucklingTimePtr ducklingMakeTime(double timestamp, DucklingTimeZoneSeriesPtr timeZoneSeries);


// Parse

//char *ducklingParseText(char *text, DucklingTimePtr time, DucklingLocalePtr locale, bool latent, DucklingDimensionPtr dimensions[]);
