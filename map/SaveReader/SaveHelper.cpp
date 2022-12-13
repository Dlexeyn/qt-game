#include "SaveHelper.h"

save::SaveHelper::SaveHelper()
{
    for(auto pair : map_char)
        map_type[pair.second] = pair.first;
}
