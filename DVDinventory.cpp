#include "DVDinventory.h"
using namespace std;
DVDInventory::DVDInventory()
{
}

DVDInventory::~DVDInventory()
{

}

void DVDInventory::borrowDVD(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D')
  {
std::set<Drama>::iterator it;
    Drama d;
    d.setDirector(firstAttribute);
    d.setTitle(secondAttribute);
    it = dramaDVDList.find(d);
    // (*it).setStock((*it).getStock()-1);
  }
  else if (DVDType == 'F')
  {
    std::set<Comedy>::iterator it;
        Comedy f;
        f.setTitle(secondAttribute);
        f.setYear (stoi(secondAttribute));
        it = comedyDVDList.find(f);
        // *it.setStock((*it).getStock()-1);
  }
  else if (DVDType == 'C')
  {
    // std::set<Classic>::iterator it;
    //     Classic c;
    //     c(firstAttribute);
    //     d.setTitle(secondAttribute);
    //     it = dramaDVDList.find(d);
    //     *it.setStock((*it).getStock()-1);
  }
}

void DVDInventory::returnDVD(char DVDType, string firstAttribute, string secondAttribute)
{
  if (DVDType == 'D')
  {

  }
  else if (DVDType == 'F')
  {

  }
  else if (DVDType == 'C')
  {

  }
}

void DVDInventory::printInventory()
{
  std::cout << "Comedies: " << '\n';
  for (Comedy const& f : comedyDVDList)
    {
        std::cout <<f.getTitle()<<" "<<f.getStock() <<" " << f.getYear()<< '\n';
    }
    std::cout << '\n';
    std::cout << "Dramas: " << '\n';
  for (Drama const& d : dramaDVDList)
    {
        std::cout << d.getTitle()<<" "<<d.getStock() <<" " << d.getYear()<< '\n';
    }
    std::cout << '\n';
    std::cout << "Classics: " << '\n';
  for (Classic const& c : classicDVDList)
    {
        std::cout << c.getTitle()<< " "<< c.getStock()<< " " << c.getYear()<< " "<< c.getMajorActor()<< '\n';
    }
}

void DVDInventory::fillInventory (ifstream &infile)
{
  while (!infile.eof())
  {
      string input;
      getline(infile, input);
      vector <string> tokens;
      stringstream s (input);
      string intermediate;

      while (!infile.eof())
      {
          string input;
          getline(infile, input);

          std::vector <string> tokens;
          stringstream s (input);
          string intermediate;

          while(getline(s, intermediate, ','))
              {
                  tokens.push_back(intermediate);
              }

            if (tokens.size()!= 0)
            {
              if (tokens[0] == "D")
              {
                Drama dramaMovie;
                dramaMovie.setStock(stoi(tokens[1]));
                dramaMovie.setDirector(tokens[2].substr(1));
                dramaMovie.setTitle(tokens[3].substr(1));
                dramaMovie.setYear(stoi(tokens[4]));
                dramaDVDList.insert(dramaMovie);
              }
              else if (tokens[0] == "F")
              {
                Comedy comedyMovie;
                comedyMovie.setStock(stoi(tokens[1]));
                comedyMovie.setDirector(tokens[2].substr(1));
                comedyMovie.setTitle(tokens[3].substr(1));
                comedyMovie.setYear(stoi(tokens[4]));
                comedyDVDList.insert(comedyMovie);
              }
              else if (tokens[0] == "C")
              {
                Classic classicMovie;
                classicMovie.setStock(stoi(tokens[1]));
                classicMovie.setDirector(tokens[2].substr(1));
                classicMovie.setTitle(tokens[3].substr(1));

                stringstream s2 (tokens[4]);
                std::vector<string> tokens2;

                while(getline(s2, intermediate, ' '))
                    {
                        tokens2.push_back(intermediate);
                    }
                classicMovie.setMajorActor(tokens2[1]+" "+tokens2[2]);
                classicMovie.setReleaseMonth(stoi(tokens2[3]));
                classicMovie.setYear(stoi(tokens2[4]));
                classicDVDList.insert (classicMovie);
              }
              else
              {
                  std::cout << "Incorrect code: " << tokens[0] << '\n';
              }
            }
        }
}
}
