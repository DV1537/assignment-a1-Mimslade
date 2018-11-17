#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
int main(int argc, const char * argv[])
{
  srand(time(NULL)); // random seed;
  int number;
  int counter;
  int *iptr;
  int accumulator;
  int average;
  std::string filename;

  std::ifstream inputFile;
  std::ofstream outputFile;
  if(argc < 2) // if no argument other then filepath passed, creates own file with numbers for testing.
  {
    std::cout << "Since you did not specify what file you wanted to open, i created one for you that generates some random numbers.\n";
    const int min = 1;
    const int max = 10;
    int namb;

    filename = "noarg.txt";

    namb = (rand() % (max - min + 1)) + min; // decides how many numbers in file.
    outputFile.open(filename); // open inputFile.
    if(outputFile.is_open())
    {
      for(int i = 0; i < namb; i++)
      {
        outputFile << (rand() % (max - min + 1)) + min << " "; // decides what numbers stored in file.
      }
      outputFile.close(); //close outputFile.
    }
    else
      return EXIT_FAILURE;
  }
  else
    filename = argv[1];

  inputFile.open(filename);

  if(inputFile.is_open())
  {
    counter = 0;
    while(inputFile >> number) //check how many numbers in file.
      counter++;

    if(counter != 0)
    {
      iptr = new int[counter]; //create dynamic array with size of numbers in file.

      //reset read position
      inputFile.clear();
      inputFile.seekg(0, std::ios::beg);

      accumulator = 0;
      std::cout << "Input: ";
      for(int i = 0; i < counter; i++)
      {
        inputFile >> iptr[i];
        std::cout << iptr[i] << " ";
        accumulator += iptr[i];
      }
      inputFile.close(); //close inputfile.
    }
    else
      return EXIT_FAILURE;
  }
  else
    return EXIT_FAILURE;

  average = accumulator / counter;
  std::cout << "\tOutput: ";

  for(int i = 0; i < counter; i++)
  {
    if(iptr[i] > average)
    {
      std::cout << iptr[i] << " ";
    }
  }

  return 0;
}
