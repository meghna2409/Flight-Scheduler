#include "Route.h"

Route::Route(int u, int v, int w, std::string lbl) {
    sourceID = u;
    destID = v;
    weight = w;
    label = lbl;
}

Route::Route() { 
    sourceID = -1;
    destID = -1;
    weight = -1;
    label = "";
}

