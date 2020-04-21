void opn(sqlite3 **b, char _fname[], int *_res);
static int selectCb(char _outM[50][10][200], int argc, char **argv, char **colNames);
void readDB(sqlite3 *b, char _outM[50][10][200],char *_sql);
void sele1(sqlite3 *bd);
void sele2(sqlite3 *bd);
