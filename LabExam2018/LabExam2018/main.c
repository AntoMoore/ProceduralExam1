#include <stdio.h>
//constants
#define SUMMER_DAY_RATE_1 0.50
#define SUMMER_DAY_RATE_2 0.75
#define SUMMER_DAY_RATE_3 1.10

#define SUMMER_NIGHT_RATE_1 0.10
#define SUMMER_NIGHT_RATE_2 0.20
#define SUMMER_NIGHT_RATE_3 0.30

#define WINTER_RATE_1 0.60
#define WINTER_RATE_2 0.85
#define WINTER_RATE_3 1.30

#define SENTINAL -1

void main()
{
	//variables
	int deptId, electricPlan, deptLow;
	float summerDay, summerNight, winterTime, totalSummerNight, annualElectricity;
	float totalAnnualElectricity = 0;
	int counterHigh = 0;
	int counterLow = 0;
	float summerNightBillHigh = 0;
	float annualBillLow = 0;
	int lessThan1000 = 0;


	//prompt user for deptID
	printf("Please Enter DepartmentID (-1 To EXIT): ");
	//initial read
	scanf("%d", &deptId);

	//sentinal control loop
	while (deptId != SENTINAL)
	{
		//prompt for inputs
		printf("\nEnter - Summer Day units, Summer Night Units, Winter Units, Electricity Plan ID \n");
		scanf("%f %f %f %d", &summerDay, &summerNight, &winterTime, &electricPlan);

		//calculate bill
		switch (electricPlan)
		{
			case 1:
				annualElectricity = (summerDay * SUMMER_DAY_RATE_1) + (summerNight * SUMMER_NIGHT_RATE_1) + (winterTime * WINTER_RATE_1);
				totalSummerNight = summerNight * SUMMER_NIGHT_RATE_1;
				break;
			case 2:
				annualElectricity = (summerDay * SUMMER_DAY_RATE_2) + (summerNight * SUMMER_NIGHT_RATE_2) + (winterTime * WINTER_RATE_2);
				totalSummerNight = summerNight * SUMMER_NIGHT_RATE_2;
				break;
			case 3:
				annualElectricity = (summerDay * SUMMER_DAY_RATE_3) + (summerNight * SUMMER_NIGHT_RATE_3) + (winterTime * WINTER_RATE_3);
				totalSummerNight = summerNight * SUMMER_NIGHT_RATE_3;
				break;
			default:
				printf("\nInvalid Electricity Plan ID");

		}//switch

		//sum for total annual electricity
		totalAnnualElectricity += annualElectricity;

		//largest night summer bill
		if ((summerNightBillHigh >= 0) && (counterHigh == 0))
		{
			summerNightBillHigh = totalSummerNight; //only runs on first pass
			counterHigh++;
		}
		else if (summerNightBillHigh < totalSummerNight)
		{
			summerNightBillHigh = totalSummerNight;
			counterHigh++;
		}

		//dept with lowest annual bill
		if ((annualBillLow <= 0) && (counterLow == 0))
		{
			annualBillLow = annualElectricity; //only runs on first pass
			deptLow = deptId;
			counterLow++;
		}
		else if (annualBillLow > annualElectricity)
		{
			annualBillLow = annualElectricity;
			deptLow = deptId;
			counterLow++;
		}

		//departments with less than 1000 summer UNITS
		if (summerNight < 1000)
		{
			lessThan1000++;
		}
	
		//output results for each department
		printf("\nDepartment %d - Total Bill: %.2f || Summer Night Bill: %.2f\n", deptId, annualElectricity, totalSummerNight);

		//subsuquent read
		printf("\nPlease Enter DepartmentID (-1 To EXIT): ");
		//initial read
		scanf("%d", &deptId);

	}//while

	//output total results
	printf("\nTotal Electricity: %.2f || Max Summer Night: %.2f || Min Dept Bill: %d || Depts under 1000 Summer Units: %d\n", totalAnnualElectricity, summerNightBillHigh, deptLow, lessThan1000);
	
}//main