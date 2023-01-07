#include "ReadData.h"

ReadData::ReadData(std::string filename_)
{

    filename = filename_;
    // std::vector<std::vector<float>> data;
    std::fstream rFile(filename); // read mode
    if (rFile.fail())
    {
        std::cout << "Error: Unable to load data file" << std::endl;
        exit(1);
    }

    std::string line;
    while (getline(rFile, line))
    {
        // loop on file lines
        std::stringstream ss(line); // build object stringstream
        float d;
        std::vector<float> temp;
        while (ss >> d)
        { // parse line words to numbers (empty space separated)
            temp.push_back(d);
        }
        ss.clear(); // erase stringstream contents
        data.push_back(temp);
    }

    rFile.close();
};

std::vector<std::vector<float>> ReadData::GetData()
{
    return data;
}

void ReadData::DumpData()
{
    std::cout << "data.size()= " << data.size() << "; "
              << "Vector Size: " << data[0].size() << std::endl;
    if (data[0].size() == 4)
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << "(" << data[i][0] << ", " << data[i][1] << ", " << data[i][2] << ", " << data[i][3] << ")" << std::endl;
        }
    }
    else if (data[0].size() == 2)
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << "(" << data[i][0] << ", " << data[i][1] << ")" << std::endl;
        }
    }
}