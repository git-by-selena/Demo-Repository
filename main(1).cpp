#include <iostream>
using namespace std;;
#include <cctype>
#include <string> 
#include <algorithm>
#include <cstring>


const int CITY_SIZE = 15;
const int PRECISION = 2;


enum CityType {ATLANTA=0, BOSTON, CHICAGO, DALLAS, DENVER, HOUSTON, LOSANGELES,MEMPHIS, MIAMI, NEWYORK, PHILADELPHIA, PHOENIX, SEATTLE, SANFRANCISCO, WASHINGTONDC, INVALID = -1};


void Precision(int SetPrecisionTo){
 //precision
  cout.setf(ios::fixed); //decimal point and trailing zeros
  cout.setf(ios::showpoint);
  cout.precision(SetPrecisionTo);
  }


const int DistanceTable [CITY_SIZE][CITY_SIZE] = {
    {0,1505,944,1157,1945,1126,3108,541,973,1200,1070,2555,3434,3503,871},
    {1505,0,1367,2491,2839,2578,4166,1824,2022,306,435,3691,4330,3997,634},
    {944,1366,0,1290,1474,1510,2444,773,1912,1145,1069,2332,2981,2787,956},
    {1157,2491,1290,0,1064,362,1990,675,1785,2204,2086,1422,2380,2701,1900},
    {1945,2838,1474,1064,0,1412,1335,1411,2773,2617,2532,942,1524,1640,2395},
    {1127,2579,1511,362,1412,0,2205,778,1544,2279,2154,1631,2641,3038,1958},
    {3108,4166,2800,1990,1335,2205,0,2573,3755,3933,3918,574,559,1544,3689},
    {541,1824,773,675,1411,778,2573,0,1404,1533,1413,2026,2893,2997,1226},
    {973,2022,1912,1785,2773,1544,3755,1404,0,1756,1643,3182,4166,4392,1487},
    {1200,306,1145,2204,2617,2279,3933,1533,1756,0,130,3441,4126,3863,328},
    {1070,435,1069,2086,2532,2154,3918,1413,1643,130,0,3342,4047,3816,199},
    {2555,3691,2332,1422,942,1631,574,2026,3182,3441,3342,0,1050,1792,3180},
    {3434,4330,2981,2380,1524,2641,559,2893,4166,4126,4047,1050,0,1092,3916},
    {3503,3997,2787,2701,1640,3038,1544,2997,4392,3863,3816,1792,1092,0,3734},
    {871,634,956,1900,2395,1958,3689,1226,1487,328,199,3180,3916,3734,0},
};


int getAverageDistance (int myDistanceTable[][CITY_SIZE], CityType cityIndex){
/* this function returns the average distance between the specified city and all other cities in the Distance table.

preconditions (myDistanceTable[][CITY_SIZE]): copied array of city distances
              (CityType dept): Enum CityType of city
postcondition  Computes and returns the total gas cost of the travel between two cities
0. Check to ensure enum is in range
1.create variable to hold sum of distances
2. create variable to count how many distances of cities there are (14 cities)
3.
*/
//CHECK TO MAKE SURE ENUMS are in RANGE
  if ((cityIndex > 15) || (cityIndex < 0)){
  return -1; 
  }
  
  int sumOfDistances = 0;
  int count = 0;
  int distanceAvg = 0;

  for (int i = 0; i < (CITY_SIZE); i++){
    sumOfDistances = sumOfDistances + myDistanceTable[cityIndex][i];
    count ++;
    //cout << "\ncity index addded is: " << myDistanceTable[cityIndex][i];
    //cout << "\n" << DistanceTable[cityIndex][i];

    //cout << i << "\n << Sum of distances is: " << sumOfDistances << " Count is: " << count << endl;
  }
  distanceAvg = sumOfDistances / (count -1); //-1 to not divide city by city
  //cout << "\n Average of distances is: " << distanceAvg << endl;
  return distanceAvg;
}


void copyDistanceTable(int myDistanceTable[][CITY_SIZE], int sizeDem1) {
  /* this function copies distances from globally declared array
preconditions (myDistanceTable): an empty array, which this function populates w/ distances
               (sizeDem1): size of myDistanceTable
postcondition will save city distances in this function & add 75 to distance from Denver to all cities west of it */
  
  for (int index1=0; index1<sizeDem1; index1++) {
    for (int index2=0; index2 < CITY_SIZE; index2++) 
      if ((index1 == CityType::DENVER && index2 == CityType::SEATTLE) || 
        (index1 == CityType::DENVER && index2 == CityType::SANFRANCISCO) ||
        (index1 == CityType::DENVER && index2 == CityType::LOSANGELES)){
          myDistanceTable [index1][index2] = DistanceTable[index1][index2] + 75;
          //cout << myDistanceTable[index1][index2];
          //cout << " ";
      } else {
          myDistanceTable [index1][index2] = DistanceTable[index1][index2];
          //cout << myDistanceTable[index1][index2];
          //cout << " ";
      } 
  //cout << myDistanceTable[index1][index2];
          
}
}


double getTravelCost (int myDistanceTable[][CITY_SIZE], CityType arrCity, CityType deptCity){
/* this function takes 3 parameters and computes and returns the total gas cost of travel between two cities using the information retrieved above. Adds $75 to all cities west of Denver becuase of I-70 closure.

preconditions (myDistanceTable[][CITY_SIZE]): copied array of city distances
              (CityType arr): Enum CityType of arrival city
              (CityType dept): Enum CityType of departure city
postcondition  Computes and returns the total gas cost of the travel between two cities

0. Check to ensure enum is in range
1. Ask user for input
2. Querry user
3. Computes and returns the total gas cost of the travel between two cities by:
(gas price * MPH) / distance
To compue distance: index(arrival) - index(depaarute), then make positive

*/
//CHECK TO MAKE SURE ENUMS are in RANGE
  if ((arrCity > 15|| deptCity > 15) || (arrCity < 0 || deptCity < 0 )){
  return -1; 
  }
  
  double distance;
  double travelCost;
  double gasPrice;
  double MPG; //miles per hour
  cout << " " << endl;
  cout << "\nEnter miles per gallon >>" << flush;
  cin >> MPG;
  cout << "Enter gas price >> " << flush;
  cin >> gasPrice;

  
  distance = myDistanceTable[arrCity][deptCity];
  //cout << "\ndistance is " << distance << endl;
  travelCost = ((distance / MPG) * gasPrice);
  //distance = myDistanceTable[arrCity][deptCity];
  //cout << "\ndistance is " << distance << endl;
  //cout << "\ncost is " << travelCost << endl;
  
  return travelCost;
  }


CityType getIndexFromString(string city) {
/*
 This function converts a string of a city name to an enum, CityType, which is an integer
representing the index.
preconditions (city): A string of a city name, that was asked for by the user in "main" funciton.
postcondition returns index of the string of the city entered, as a CityType value.
 */
  
  CityType index; //the CityType enum value

  //cout << "my city before upper and whitespace" << city << endl;
  //converts string of city to all lowercase
  for (int i = 0; i < city.length(); i++) {
      city[i] = toupper(city[i]);
  }  
  //cout << city;
  city.erase(remove(city.begin(),city.end(),' '),city.end());

  cout << city;
  //conver the lowercased city string to the enum CITY value
  if (city == "ATLANTA") {
      index = CityType::ATLANTA;
  } else if (city == "BOSTON") {
      index = CityType::BOSTON;
  } else if (city == "CHICAGO") {
      index = CityType::CHICAGO;
  } else if (city == "DALLAS") {
      index = CityType::DALLAS;
  } else if (city == "DENVER") {
      index = CityType::DENVER;
  } else if (city == "HOUSTON") {
      index = CityType::HOUSTON;
  } else if (city == "LOSANGELES") {
      index = CityType::LOSANGELES;
  } else if (city == "MEMPHIS") {
      index = CityType::MEMPHIS;
  } else if (city == "MIAMI") {
      index = CityType::MIAMI;
  } else if (city == "NEWYORK") {
      index = CityType::NEWYORK;
  } else if (city == "PHILADELPHIA") {
      index = CityType::PHILADELPHIA;
  } else if (city == "PHOENIX") {
      index = CityType::PHOENIX;
  } else if (city == "SEATTLE") {
      index = CityType::SEATTLE;
  } else if (city == "SANFRANCISCO") {
      index = CityType::SANFRANCISCO;
  } else if (city == "WASHINGTONDC"){
      index = CityType::WASHINGTONDC;
  } else {
    index = CityType::INVALID;
  }
    return index;
  }


int main() { 
  string arr; //arrival city
  string dept; //departure city
  double travelCost;
  CityType arivalIndex, DeptIndex;
  double distanceAvg; 
  int myDistanceTable[CITY_SIZE][CITY_SIZE]; //creates empty array

  //GATHER USER INPUT    
  cout << "Enter arrival city >> " << flush;
  getline(cin, arr); 
  cout << "Enter departure city >> " << flush;
  getline(cin, dept);
  

  //FUNCTION CALLS
  Precision(PRECISION);
  copyDistanceTable(myDistanceTable, CITY_SIZE);

  CityType arrivalCity = getIndexFromString(arr);
  //cout << arrivalCity << endl;

  CityType departureCity = getIndexFromString(dept);
  //cout << departureCity << endl;

  travelCost = getTravelCost(myDistanceTable, arrivalCity, departureCity);
  cout << "\nTravel cost is: $" << travelCost << " dollars" << endl;

 distanceAvg = getAverageDistance (myDistanceTable, arrivalCity);
  cout << "\nAverage distnaces between the specified city (arrival city)  and all other cities in myDistance table is: " << distanceAvg << endl;
  }



