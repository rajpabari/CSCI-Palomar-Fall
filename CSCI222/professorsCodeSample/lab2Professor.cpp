#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

#define TRACKS 2
#define SEG_PER_TRACK 10
#define NTRAIN 4
#define SIMTIME 3

struct Segment {
  int train;
  Segment *next;
  Segment *prev;
  Segment *next_adj;
  Segment *prev_adj;
};

void init_tracks(Segment *segments[TRACKS][SEG_PER_TRACK]);
void print_track(Segment *segments[TRACKS][SEG_PER_TRACK]);
void move_train(Segment *segments[TRACKS][SEG_PER_TRACK]);

void init_tracks(Segment *segments[TRACKS][SEG_PER_TRACK]) {

  for (int i = 0; i < TRACKS; i++) {
    for (int j = 0; j < SEG_PER_TRACK; j++) {
      segments[i][j] = new Segment;
    }
  }

  srand(time(0));

  for (int i = 0; i < TRACKS; i++) {
    for (int j = 0; j < SEG_PER_TRACK; j++) {
      int knext, kprev;

      knext = (j + 1) % SEG_PER_TRACK;
      kprev = (j + SEG_PER_TRACK - 1) % SEG_PER_TRACK;

      segments[i][j]->next = segments[i][knext];
      segments[i][j]->prev = segments[i][kprev];
      segments[i][j]->next_adj = segments[TRACKS - 1 - i][knext];
      segments[i][j]->prev_adj = segments[TRACKS - 1 - i][kprev];
    }
  }

  for (int i = 0; i < TRACKS; i++) {
    for (int j = 0; j < SEG_PER_TRACK; j++) {
      segments[i][j]->train = 0;
    }
  }

  int n = 0;

  while (n < NTRAIN) {

    int t = rand() % 2;
    int s = rand() % 10;
    int d = 2 * (rand() % 2) - 1;

    if (segments[t][s]->train == 0) {
      segments[t][s]->train = d;
      n++;
    }
  }
}

// move_train
void move_train(Segment *segments[TRACKS][SEG_PER_TRACK]) {

  for (int i = 0; i < TRACKS; i++) {
    for (int j = 0; j < SEG_PER_TRACK; j++) {

      Segment *t_seg = segments[i][j];

      if (t_seg->train == 1) {
        if (t_seg->next->train == 0) {
          t_seg->train = 0;
          t_seg->next->train = 2;
        } else if (t_seg->next_adj->train == 0) {
          t_seg->train = 0;
          t_seg->next_adj->train = 2;
        }
      } else if (t_seg->train == -1) {
        if (t_seg->prev->train == 0) {
          t_seg->train = 0;
          t_seg->prev->train = -2;
        } else if (t_seg->prev_adj->train == 0) {
          t_seg->train = 0;
          t_seg->prev_adj->train = -2;
        }
      }
    }
  }

  for (int i = 0; i < TRACKS; i++)
    for (int j = 0; j < SEG_PER_TRACK; j++)
      if (segments[i][j]->train == 2 || segments[i][j]->train == -2)
        segments[i][j]->train = segments[i][j]->train / 2;
}

void print_track(Segment *segments[TRACKS][SEG_PER_TRACK]) {
  cout << "+-";
  for (int i = 0; i < SEG_PER_TRACK / 2; i++) {
    if (segments[0][i]->train == 0)
      cout << "---";
    else if (segments[0][i]->train == 1)
      cout << "->-";
    else
      cout << "-<-";
  }

  cout << "-+" << endl;

  cout << "|   X   X   X   X   X   |" << endl;

  cout << "|   ";

  for (int i = 0; i < SEG_PER_TRACK / 2; i++) {
    if (segments[1][i]->train == 0)
      cout << "---";
    else if (segments[1][i]->train == 1)
      cout << "->-";
    else
      cout << "-<-";
  }

  cout << "   |" << endl;

  cout << "|   |                  |   |" << endl;

  cout << "|   ";
  for (int i = SEG_PER_TRACK - 1; i >= SEG_PER_TRACK / 2; i--) {
    if (segments[1][i]->train == 0)
      cout << "---";
    else if (segments[1][i]->train == 1)
      cout << "->-";
    else
      cout << "-<-";
  }

  cout << "   |" << endl;
  cout << "|   X   X   X   X   X   |" << endl;

  cout << "+-";
  for (int i = SEG_PER_TRACK - 1; i >= SEG_PER_TRACK / 2; i--) {
    if (segments[0][i]->train == 0)
      cout << "---";
    else if (segments[0][i]->train == 1)
      cout << "->-";
    else
      cout << "-<-";
  }

  cout << "-+" << endl;
}

int main() {
  Segment *segments[TRACKS][SEG_PER_TRACK];

  init_tracks(segments);
  print_track(segments);

  for (int i = 0; i < SIMTIME; i++) {
    move_train(segments);
    print_track(segments);
  }

  return 0;
}
