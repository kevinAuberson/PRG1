//---------------------------------------------------------
// Fichier  : main.cpp
// Auteur   : Dani Tiago Faria Dos Santos & Kimberly Beyeler
// Date     : 06.10.2022
// But      : Logiciel permetant de calculer le trajet en taxi selon le nombre de baggages, trajet/temps et trajet jour
//            ou nuit.
//
// Remarque : R.A.S
//
// Modifs   : Ajout du calcul du trajet avec la différence de prix jour et nuit
//
// Compilateur
//---------------------------------------------------------
//---------------------------------------------------------
// Fichier  	: main.cpp
// Auteur   	: Martin Derleth & Kevin Auberson
// Date     	: 13.10.2022
// But      	: Logiciel permetant de calculer le trajet en taxi selon le nombre de baggages, trajet/temps et trajet jour
//            	  ou nuit.
//
// Remarque 	: - Source stoi: https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
//					  - Source substr: https://stackoverflow.com/questions/34097048/selecting-only-the-first-few-characters-in-a-string-c
//
// Modifs   	: Ajout des tarifs (jour / nuit) qui sont appliqués de manière effective sur la durée du trajet.
//
// Compilateur : Mingw-w64 g++ 12.1.0
//---------------------------------------------------------

/**********************************************************************************************************************/
// Header files and using namespace
/**********************************************************************************************************************/

#include <iostream>        //Used for cout and cin
#include <iomanip>         //Used for setw(...) and setprecision(...)
#include <limits>          //Used for setting numerical limits
#include <bits/stdc++.h>   //Used for modf(), https://www.geeksforgeeks.org/modf-in-cc/
#include <cstdlib>         //EXIT_SUCCESS

using namespace std;       //Usefull to skipp the std:: part when using cout or cin for example

#define BUFFER_CLEAR cin.ignore(numeric_limits<streamsize>::max(), '\n')

/**********************************************************************************************************************/

int main() {

/**********************************************************************************************************************/
// Constants and variables for the main() function
/**********************************************************************************************************************/

	//Constant value used to select the maximal number of decimal after a dot
	const int   DECIMALS =  2;
	//Constant value for the userinterface (setw())
	const int 	WIDTH    =  10;
	const int 	WIDTH2   =  10;
	//Constant value used in the if
	const int 	MIN_LUGGAGE 	= 0;
	const int 	MAX_LUGGAGE 	= 4;
	const int 	MIN_DISTANCE 	= 0;
	const int 	MAX_DISTANCE 	= 500;
	const int 	MIN_SPEED		= 50;
	const int 	MAX_SPEED		= 120;
	const int 	MIN_HOURS		= 0;
	const int 	MAX_HOURS		= 23;
	const int 	MIN_MINUTES		= 0;
	const int 	MAX_MINUTES		= 59;

	// IMPORTANT, as we work with a time system from 0 to 60 and numerical values from 0 to 100 are used we will need
	// to convert them. Example, 8.50f --> 8min + 50/100*60 = 8min 30sec
	// To simplify the calculation, this programm will also round the seconds so the work values will be plain minutes
	const double BASE_TAX			=	5.00;
	const double LUGGAGE_TAX 		=  2.60;
	const double DAY_RIDE_COST		=  1.00;
	const double NIGHT_RIDE_COST 	=  1.60;
	const double DAYTIME 			=  8.00;
	const double NIGHTTIME 			=  20.00;
	const double MIN_PER_HOUR 		=  60.00;

	//String use for the cin hours
	string departureValue;

	double 	timeValue;
	double	timeDayCost;
	double	timeNightCost;
	double	timeSpentDay;
	double	timeSpentNight;
	double	luggageCost;
	double	totalValue;

	int luggageValue;
	int speedValue;
	int distanceValue;
	int departureMinutes;
	int departureHours;

/**********************************************************************************************************************/
// Display
/**********************************************************************************************************************/


	cout << "Bienvenue sur le calculateur de course en taxi (Euros)" << endl;
	cout << "======================================================" << endl;

		  // setprecision allow us to fix a maximal amount of decimals after the dot (.)
		  // See DECIMALS value for more informations
	cout << fixed << setprecision(DECIMALS);

	cout	  << " - Prise en charge   : " << setw(WIDTH)      << BASE_TAX             << endl;
	cout	  << " - Supp. par bagage  : " << setw(WIDTH)      << LUGGAGE_TAX          << endl;
	cout	  << " - Tarif/min (jour)  : " << setw(WIDTH)      << DAY_RIDE_COST        << endl;
	cout	  << " - Tarif/min (nuit)  : " << setw(WIDTH)      << NIGHT_RIDE_COST      << endl;
	cout	  << " - Heures de jour    : " << setw(WIDTH)      << DAYTIME  << "h-" << NIGHTTIME << "h" << endl;
	cout	  << endl;

/**********************************************************************************************************************/

	cout << "Votre commande" << endl;
	cout << "==============" << endl;

	cout << "- Nbre de bagage      [0 - 4] : ";
	cin >> luggageValue;
	BUFFER_CLEAR;
	if (luggageValue < MIN_LUGGAGE or luggageValue > MAX_LUGGAGE) {
		cout << "Valeur incorrect";
		return EXIT_FAILURE;
	}


	cout << "- Distance [km]     [0 - 500] : ";
	cin >> distanceValue;
	BUFFER_CLEAR;
	if  (distanceValue < MIN_DISTANCE or distanceValue > MAX_DISTANCE) {
		cout << "Valeur incorrect";
		return EXIT_FAILURE;
	}


	cout << "- Vitesse [km/h]   [50 - 120] : ";
	cin >> speedValue;
	BUFFER_CLEAR;
	if (speedValue < MIN_SPEED or speedValue > MAX_SPEED) {
		cout << "Valeur incorrect";
		return EXIT_FAILURE;
	}


	cout << "- Depart              [hh:mm] : ";
	cin >> departureValue;
	BUFFER_CLEAR;
	//Extract the value hours and minute from the string and initialize each in a variable
	departureMinutes = stoi(departureValue.substr(3,2));
	departureHours = stoi(departureValue.substr(0,2));

	if ((departureHours < MIN_HOURS or departureHours > MAX_HOURS) or
	   (departureMinutes < MIN_MINUTES or departureMinutes > MAX_MINUTES)) {
		cout << "Valeur incorrect";
		return EXIT_FAILURE;
	}

	cout << endl;

/**********************************************************************************************************************/
// Where the magic happens, calculation area for the ticket output
/**********************************************************************************************************************/

	// Calculates the travel time and converts it into minutes
	timeValue = round(((double) distanceValue / speedValue) * MIN_PER_HOUR);

	// Reminder : 12h = 720 min  = 1 day/night cycle
	// Nb : Max distance / min speed cant be greater than 600 min (10h) in our case, but we will keep this condition for
	//      a future upgrade or if the owner wants to change the Max and Min values

	//Daytime departure
	//If the daytime departure is during the day, and if the taxi ride goes during the day and night circle, calculates
	//the cost for the time during the day and the time during the night.
	//Otherwise, if the departure is during the day and it doesn't exceed the day, calculates the cost for the day only
	if (departureHours >= DAYTIME and departureHours < NIGHTTIME) {

		if (timeValue + (departureHours * MIN_PER_HOUR) + departureMinutes > NIGHTTIME * MIN_PER_HOUR) {

			timeSpentNight = (((departureHours * MIN_PER_HOUR) + departureMinutes) + timeValue) - NIGHTTIME * MIN_PER_HOUR;
			timeSpentDay 	= timeValue - timeSpentNight;
			timeDayCost 	= DAY_RIDE_COST * timeSpentDay;
			timeNightCost 	= NIGHT_RIDE_COST * timeSpentNight;

		} else {

			timeDayCost 	= DAY_RIDE_COST * timeValue;
			timeSpentDay   = timeValue;
			//Initialization of non-used variables to avoid "ghost" values
			timeNightCost  = 0;
			timeSpentNight = 0;

		}

	} else {
		//Nighttime departure
		//Opposite of above, if the ride starts during the night but ends during the day calculates the price for both day
		//and night travel time.
		//Otherwise, if the departure is during the night and ends in the same night, calculates the night cost.
		if (timeValue + (departureHours * MIN_PER_HOUR) + departureMinutes > DAYTIME * MIN_PER_HOUR
		and timeValue + (departureHours * MIN_PER_HOUR) + departureMinutes < NIGHTTIME * MIN_PER_HOUR) {

			timeSpentDay 	= departureHours * MIN_PER_HOUR + departureMinutes + timeValue - DAYTIME * MIN_PER_HOUR;
			timeSpentNight = timeValue - timeSpentDay;
			timeNightCost 	= NIGHT_RIDE_COST * timeSpentNight;
			timeDayCost 	= DAY_RIDE_COST * timeSpentDay;

		} else {

			timeNightCost 	= NIGHT_RIDE_COST * timeValue;
			timeSpentNight = timeValue;
			//Initialization of non-used variables to avoid "ghost" values
			timeDayCost    = 0;
			timeSpentDay   = 0;

		}

	}

	luggageCost = LUGGAGE_TAX * luggageValue;
	totalValue = BASE_TAX + luggageCost + timeDayCost + timeNightCost;

/**********************************************************************************************************************/
// Ticket display
/**********************************************************************************************************************/

	cout << "votre ticket " << endl;
	cout << "============ " << endl;
	cout << "  - Prise en charge   : " << BASE_TAX    << endl;
	cout << "  - Supp bagages      : " << luggageCost << endl;
	cout << "  - Prix de la course"                   << endl;
	cout << setw(WIDTH) <<  timeSpentDay  << " @ " <<	DAY_RIDE_COST  << setw(WIDTH2) << " : " <<  timeDayCost  << endl;
	cout << setw(WIDTH) << timeSpentNight << " @ " << NIGHT_RIDE_COST << setw(WIDTH2) << " : " << timeNightCost << endl;
	cout << "  - Total             : " << totalValue  << endl;

/**********************************************************************************************************************/
// Terminate program
/**********************************************************************************************************************/

	cout << "presser ENTER pour quitter " << endl;
	BUFFER_CLEAR;

	return EXIT_SUCCESS ;
}