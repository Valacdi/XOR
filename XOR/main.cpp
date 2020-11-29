#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class XOR
{
  private:
    int skaicius1, skaicius2;

  public:
    vector<int> KonvertuotiIDvejetaine(int skaicius, vector<int> &vektorius);
    void NOT(vector<int> &vektorius);
    void AND(vector<int> vektorius1, vector<int> vektorius2, vector<int> &rezultatas);
    void OR(vector<int> vektorius1, vector<int> vektorius2, vector<int> &rezultatas);
    void NAND(vector<int> vektorius1, vector<int> vektorius2, vector<int> &rezultatas);
    void XOR1(int skaicius1, int skaicius2);
    void XOR2(int skaicius1, int skaicius2);
    void XOR3(int skaicius1, int skaicius2);
    void XOR4(int skaicius1, int skaicius2);
};

vector<int> XOR::KonvertuotiIDvejetaine(int skaicius, vector<int> &vektorius)
{
    while (skaicius > 0)
    {
      vektorius.push_back(skaicius % 2);
      skaicius = skaicius / 2;
    }
    reverse(vektorius.begin(), vektorius.end());
    for (int i = vektorius.size(); i < 32; i++)
    {
        vektorius.insert(vektorius.begin(), 0);
    }
    return vektorius;
}

void XOR::NOT(vector<int> &vektorius)
{
    for (int i = 0;i<32;i++)
    {
        if (vektorius[i] == 0)
        {
            vektorius[i] = 1;
        }
        else
        {
            vektorius[i] = 0;
        }
    }
}

void XOR::AND(vector<int> vektorius1, vector<int> vektorius2, vector<int> &rezultatas)
{
    for (int i = 0;i<32;i++)
    {
        if ((vektorius1[i] == 0) && (vektorius2[i] == 0))
        {
            rezultatas[i] = 0;
        }
        else if ((vektorius1[i] == 0) && (vektorius2[i] == 1))
        {
            rezultatas[i] = 0;
        }
        else if ((vektorius1[i] == 1) && (vektorius2[i] == 0))
        {
            rezultatas[i] = 0;
        }
        else
        {
            rezultatas[i] = 1;
        }
    }
}

void XOR::OR(vector<int> vektorius1, vector<int> vektorius2, vector<int> &rezultatas)
{
  for (int i = 0;i<32;i++)
    {
        if ((vektorius1[i] == 0) && (vektorius2[i] == 0))
        {
            rezultatas[i] = 0;
        }
        else if ((vektorius1[i] == 0) && (vektorius2[i] == 1))
        {
            rezultatas[i] = 1;
        }
        else if ((vektorius1[i] == 1) && (vektorius2[i] == 0))
        {
            rezultatas[i] = 1;
        }
        else
        {
            rezultatas[i] = 1;
        }
    }
}

void XOR::NAND(vector<int> vektorius1, vector<int> vektorius2, vector<int> &rezultatas)
{
    for (int i = 0;i<32;i++)
    {
        if ((vektorius1[i] == 0) && (vektorius2[i] == 0))
        {
            rezultatas[i] = 1;
        }
        else if ((vektorius1[i] == 0) && (vektorius2[i] == 1))
        {
            rezultatas[i] = 1;
        }
        else if ((vektorius1[i] == 1) && (vektorius2[i] == 0))
        {
            rezultatas[i] = 1;
        }
        else
        {
            rezultatas[i] = 0;
        }
    }
}

void XOR::XOR1(int skaicius1, int skaicius2)
{
    ofstream fr("rezultatas.csv", ios::app);
    vector<int> A, B, ANOT, BNOT, rez1(32), rez2(32), rez(32);
    A = KonvertuotiIDvejetaine(skaicius1, A);
    B = KonvertuotiIDvejetaine(skaicius2, B);
    ANOT = KonvertuotiIDvejetaine(skaicius1, ANOT);
    BNOT = KonvertuotiIDvejetaine(skaicius2, BNOT);

    NOT(ANOT);
    NOT(BNOT);
    AND(ANOT, B, rez1);
    AND(BNOT, A, rez2);
    OR(rez1, rez2, rez);

    fr << "XOR1:" << ",";
    for (int i = 0;i<32;i++)
    {
        fr << rez[i] << ",";
    }
    fr << endl;
}

void XOR::XOR2(int skaicius1, int skaicius2)
{
    ofstream fr("rezultatas.csv", ios::app);
    vector<int> A, B, rez1(32), rez2(32), rez3(32), rez(32);
    A = KonvertuotiIDvejetaine(skaicius1, A);
    B = KonvertuotiIDvejetaine(skaicius2, B);

    NAND(A, B, rez1);
    NAND(B, rez1, rez2);
    NAND(A, rez1, rez3);
    NAND(rez3, rez2, rez);

    fr << "XOR2:" << ",";
    for (int i = 0;i<32;i++)
    {
        fr << rez[i] << ",";
    }
    fr << endl;
    fr.close();
}

void XOR::XOR3(int skaicius1, int skaicius2)
{
    ofstream fr("rezultatas.csv", ios::app);
    vector<int> A, B, rez1(32), rez2(32), rez(32);
    A = KonvertuotiIDvejetaine(skaicius1, A);
    B = KonvertuotiIDvejetaine(skaicius2, B);

    AND(A, B, rez1);
    OR(A, B, rez2);
    NOT(rez1);
    AND(rez1, rez2, rez);

    fr << "XOR3:" << ",";
    for (int i = 0;i<32;i++)
    {
        fr << rez[i] << ",";
    }
    fr << endl;
    fr.close();
}

void XOR::XOR4(int skaicius1, int skaicius2)
{
    ofstream fr("rezultatas.csv", ios::app);
    vector<int> A, B, ANOT, BNOT, rez1(32), rez2(32), rez(32);
    A = KonvertuotiIDvejetaine(skaicius1, A);
    B = KonvertuotiIDvejetaine(skaicius2, B);
    ANOT = KonvertuotiIDvejetaine(skaicius1, ANOT);
    BNOT = KonvertuotiIDvejetaine(skaicius2, BNOT);

    NOT(ANOT);
    NOT(BNOT);
    OR(ANOT, BNOT, rez1);
    OR(A, B, rez2);
    AND(rez1, rez2, rez);

    fr << "XOR4:" << ",";
    for (int i = 0;i<32;i++)
    {
        fr << rez[i] << ",";
    }
    fr << endl;
    fr.close();
}

int main(int argc, char* argv[])
{
    XOR atlikti;
    ofstream fr("rezultatas.csv", ios::app);
    int skaicius1, skaicius2;

    skaicius1 = atoi(argv[1]); ///char i int
    skaicius2 = atoi(argv[2]);
    fr << "Pirmas skaicius:" << "," << skaicius1 << endl;
    fr << "Antras skaicius:" << "," << skaicius2 << endl << endl;

    atlikti.XOR1(skaicius1, skaicius2);
    atlikti.XOR2(skaicius1, skaicius2);
    atlikti.XOR3(skaicius1, skaicius2);
    atlikti.XOR4(skaicius1, skaicius2);

    fr.close();

  return 0;
}
