float CalculateTax(float salary)
{
    float tax = -1;
    if (salary >= 0)//Used to prevent bad input, eg. negative value
    { 
        tax = 0;
        if (salary > 1000000)
        {
            if (salary <= 1500000)
                tax += (salary - 1000000) * 0.05;
            else if (salary > 1500000)
            {
                tax += 499999 * 0.05; //max by now is 24999
                if (salary <= 8500000)
                    tax += (salary - 1500000) * 0.1;
                else if (salary > 8500000)
                {
                    tax += 6999999 * 0.1; //max by now is 724999
                    if (salary <= 12500000)
                        tax += (salary - 8500000) * 0.15;
                    else if (salary > 12500000)
                    {
                        tax += 3999999 * 0.15; //max by now is 1324999
                        tax += (salary - 12500000) * 0.2;
                    }
                }
            }
        }
    }
    
    return tax;
}