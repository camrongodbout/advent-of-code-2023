//============================================================================
// Name        : day1.cpp
// Author      : Camron Godbout
// Version     :
// Copyright   : Your copyright notice
// Description : Day of Advent of Code with CUDA C++
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

// CUDA kernel
//__global__ void

int
main ()
{
  std::ifstream file ("input.txt");
  std::vector<int> calibrationValues;

  if (!file.is_open ())
    {
      std::cerr << "Unable to open file\n";
      return 1;
    }
  std::string line;
  while (getline (file, line))
    {
      std::string firstDigit = "", lastDigit = "";

      // Find the first digit
      for (char c : line)
	{
	  if (isdigit (c))
	    {
	      firstDigit = c;
	      break;
	    }
	}

      // Find the last digit
      for (auto it = line.rbegin (); it != line.rend (); ++it)
	{
	  if (isdigit (*it))
	    {
	      lastDigit = *it;
	      break;
	    }
	}

      // Combine and convert to integer, then add to the vector
      if (!firstDigit.empty () && !lastDigit.empty ())
	{
	  int calibrationValue = std::stoi (firstDigit + lastDigit);
	  calibrationValues.push_back (calibrationValue);
	}
    }

  file.close ();

  for (int value : calibrationValues)
    {
      std::cout << value << std::endl;
    }

  return 0;
}
