#include "fun.h"

error_t isValidDate(Date *validDate)
{
    /// check range of year,month and day
    if (validDate->yyyy > MAX_YR || validDate->yyyy < MIN_YR)
        return FAILURE;
    if (validDate->mm < 1 || validDate->mm > 12)
        return FAILURE;
    if (validDate->dd < 1 || validDate->dd > 31)
        return FAILURE;

    /// Handling feb days in leap year
    if (validDate->mm == 2)
    {
        if (leap_year(validDate->yyyy))
        {
            if(validDate->dd <= 29)
            {
                return SUCCESS;
            }
            return FAILURE;
        }
        else
        {
            if (validDate->dd <= 28)
                return SUCCESS;
            return FAILURE;
        }
    }
    /// handling months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 || validDate->mm == 9 || validDate->mm == 11)
        if (validDate->dd <= 30)
        {
            return SUCCESS;
        }
        else
            return FAILURE;
    return SUCCESS;
}