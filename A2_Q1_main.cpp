#include <iostream>

using namespace std;

struct Stat
{
  // vars
  float min;
  float avg;
  float max;
};

//prototypes
Stat statMonth(Stat** tableTemp, int month, int nYears) {
  // get month to correspond with array indexes
  month = month - 1;
  Stat * s;
  s = new Stat[12];
  for (int i  = 0; i < 12; i++) {
    Stat * temp;
    temp = new Stat;
    float min, avg, max;
    for (int j = 0; j < nYears; j++) {
      if (j == 0) {
        min = tableTemp[j][month].min;
        avg = tableTemp[j][month].avg;
        max = tableTemp[j][month].avg;
      } else {
        if (tableTemp[j][i].min < min) {
          min = tableTemp[j][i].min;
        }
        if (tableTemp[j][i].max > max) {
          max = tableTemp[j][i].max;
        }
        avg += tableTemp[j][i].avg;
      }
    }
    temp->min = min;
    temp->max = max;
    temp->avg = avg / 10;
    s[i] = *temp;
    delete temp;
  }

  return s[month];
}

void printMonth(Stat& tableTemp, int month) {
  month  = month - 1;
  // month names corresponding to the int month
  string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  cout << "For the month of " << months[month];
  cout << "\nThe minimum temperature was = " << tableTemp.min;
  cout << "\nThe average temperature was = " << tableTemp.avg;
  cout << "\nThe maximum temperature was = " << tableTemp.max;
}



int main()
{
    float year19[12][3] = { {-15,-12,-9},{-12,-9,-6},{-8,-4,-1},{1,5,9},{7,11,15},{12,17,22},{17,22,27},{14,19,24},{10,15,20},{5,9,13},{-5,-2,2},{-7,-4,-1} };
    float year18[12][3] = { {-13,-9,-5},{-9,-5,0},{-4,-1,2},{-1,3,7},{8,15,21},{12,17,23},{17,22,28},{17,21,26},{12,17,21},{3,7,11},{-4,-1,2},{-8,-5,-2} };
    float year17[12][3] = { {-11,-7,-3},{-11,-6,-2},{-9,-6,-2},{3,7,11},{7,11,16},{12,17,22},{15,20,25},{13,19,24},{13,18,23},{9,13,17},{-3,1,5},{-11,-9,-6} };
    float year16[12][3] = { {-11,-7,-4},{-13,-9,-4},{-6,-2,1},{-1,3,8},{8,13,18},{12,17,22},{15,20,25},{16,21,26},{11,17,22},{6,9,13},{0,4,7},{-9,-6,-2} };
    float year15[12][3] = { {-18,-13,-8},{-22,-17,-12},{-10,-6,-2},{1,5,10},{9,15,22},{11,17,22},{14,20,26},{15,20,25},{12,17,22},{4,8,12},{2,5,8},{-1,1,4} };
    float year14[12][3] = { {-17,-12,-8},{-16,-11,-7},{-12,-8,-3},{0,4,8},{7,13,18},{12,17,23},{13,18,24},{13,18,24},{10,15,20},{6,10,14},{-2,1,4},{-6,-4,-1} };
    float year13[12][3] = { {-15,-10,-5},{-14,-10,-5},{-6,-3,0},{0,4,9},{8,13,19},{11,16,21},{15,20,26},{13,19,25},{8,14,19},{6,9,13},{-5,-1,3},{-13,-9,-6} };
    float year12[12][3] = { {-14,-9,-5},{-12,-7,-2},{-1,3,7},{1,6,10},{9,14,20},{12,18,23},{14,20,25},{15,19,24},{9,14,19},{6,10,14},{-2,1,4},{-8,-5,-1} };
    float year11[12][3] = { {-14,-11,-7},{-13,-9,-4},{-7,-4,0},{1,5,10},{7,12,17},{12,17,22},{15,21,26},{14,19,23},{11,16,20},{6,10,13},{1,5,9},{-6,-3,0} };
    float year10[12][3] = { {-10,-7,-4},{-7,-5,-3},{-1,3,6},{4,9,14},{8,14,20},{12,17,22},{16,21,26},{14,19,24},{10,15,19},{4,8,11},{-2,2,5},{-8,-6,-3} };

   //Create 10x12 dynamic array with struct stat
    Stat** tableTemp = new Stat*[10];
    for (int i = 0; i < 10; i++){
        tableTemp[i] = new Stat[12];
        if (i == 0) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year10[i][0];
            s->avg = year10[i][1];
            s->max = year10[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 1) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year11[i][0];
            s->avg = year11[i][1];
            s->max = year11[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 2) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year12[i][0];
            s->avg = year12[i][1];
            s->max = year12[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 3) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year13[i][0];
            s->avg = year13[i][1];
            s->max = year13[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 4) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year14[i][0];
            s->avg = year14[i][1];
            s->max = year14[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 5) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year15[i][0];
            s->avg = year15[i][1];
            s->max = year15[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 6) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year16[i][0];
            s->avg = year16[i][1];
            s->max = year16[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 7) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year17[i][0];
            s->avg = year17[i][1];
            s->max = year17[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 8) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year18[i][0];
            s->avg = year18[i][1];
            s->max = year18[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        } else if (i == 9) {
          for (int j = 0; j < 12; j++) {
            Stat * s = new Stat;
            s->min = year19[i][0];
            s->avg = year19[i][1];
            s->max = year19[i][2];
            tableTemp[i][j] = *s;
            delete s;
          }
        }
    }
    // test for sept 
    Stat sm = statMonth(tableTemp, 9, 10);
    printMonth(sm, 9);

    return 0;
}
