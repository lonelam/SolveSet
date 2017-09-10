#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int st[72];
int b[72];
int i, t, flg;
bool check(int st[72])
{
  for (int i = 0; i < 72; i++)
  {
    if (st[i] != st[i / 9 * 9])
    {
      return false;
    }
  }
  return true;
}
bool dfs(int st[72], int k)
{
  if (check(st))
  {
    return true;
  }
  if (k == 3)
  {
    return check(st);
  }
  int b[72];
  memcpy(b, st, sizeof(b));
		{
      memcpy(st, b, sizeof(b));
			t = st[0]; st[0] = st[4]; st[4] = st[8]; st[8] = t;
			t = st[1]; st[1] = st[6]; st[6] = st[3]; st[3] = t;
			t = st[2]; st[2] = st[5]; st[5] = st[7]; st[7] = t;
			t = st[9]; st[9] = st[35]; st[35] = st[40]; st[40] = t;
			t = st[11]; st[11] = st[34]; st[34] = st[41]; st[41] = t;
			t = st[10]; st[10] = st[30]; st[30] = st[42]; st[42] = t;
			t = st[14]; st[14] = st[29]; st[29] = st[43]; st[43] = t;
			t = st[13]; st[13] = st[27]; st[27] = st[44]; st[44] = t;
			t = st[18]; st[18] = st[67]; st[67] = st[53]; st[53] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[9]; st[9] = st[13]; st[13] = st[17]; st[17] = t;
			t = st[10]; st[10] = st[15]; st[15] = st[12]; st[12] = t;
			t = st[11]; st[11] = st[14]; st[14] = st[16]; st[16] = t;
			t = st[18]; st[18] = st[8]; st[8] = st[49]; st[49] = t;
			t = st[20]; st[20] = st[7]; st[7] = st[50]; st[50] = t;
			t = st[19]; st[19] = st[3]; st[3] = st[51]; st[51] = t;
			t = st[23]; st[23] = st[2]; st[2] = st[52]; st[52] = t;
			t = st[22]; st[22] = st[0]; st[0] = st[53]; st[53] = t;
			t = st[27]; st[27] = st[40]; st[40] = st[62]; st[62] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[18]; st[18] = st[22]; st[22] = st[26]; st[26] = t;
			t = st[19]; st[19] = st[24]; st[24] = st[21]; st[21] = t;
			t = st[20]; st[20] = st[23]; st[23] = st[25]; st[25] = t;
			t = st[27]; st[27] = st[17]; st[17] = st[58]; st[58] = t;
			t = st[29]; st[29] = st[16]; st[16] = st[59]; st[59] = t;
			t = st[28]; st[28] = st[12]; st[12] = st[60]; st[60] = t;
			t = st[32]; st[32] = st[11]; st[11] = st[61]; st[61] = t;
			t = st[31]; st[31] = st[9]; st[9] = st[62]; st[62] = t;
			t = st[0]; st[0] = st[49]; st[49] = st[71]; st[71] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[27]; st[27] = st[31]; st[31] = st[35]; st[35] = t;
			t = st[28]; st[28] = st[33]; st[33] = st[30]; st[30] = t;
			t = st[29]; st[29] = st[32]; st[32] = st[34]; st[34] = t;
			t = st[0]; st[0] = st[26]; st[26] = st[67]; st[67] = t;
			t = st[2]; st[2] = st[25]; st[25] = st[68]; st[68] = t;
			t = st[1]; st[1] = st[21]; st[21] = st[69]; st[69] = t;
			t = st[5]; st[5] = st[20]; st[20] = st[70]; st[70] = t;
			t = st[4]; st[4] = st[18]; st[18] = st[71]; st[71] = t;
			t = st[9]; st[9] = st[58]; st[58] = st[44]; st[44] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[36]; st[36] = st[40]; st[40] = st[44]; st[44] = t;
			t = st[37]; st[37] = st[42]; st[42] = st[39]; st[39] = t;
			t = st[38]; st[38] = st[41]; st[41] = st[43]; st[43] = t;
			t = st[63]; st[63] = st[53]; st[53] = st[4]; st[4] = t;
			t = st[65]; st[65] = st[52]; st[52] = st[5]; st[5] = t;
			t = st[64]; st[64] = st[48]; st[48] = st[6]; st[6] = t;
			t = st[68]; st[68] = st[47]; st[47] = st[7]; st[7] = t;
			t = st[67]; st[67] = st[45]; st[45] = st[8]; st[8] = t;
			t = st[54]; st[54] = st[13]; st[13] = st[35]; st[35] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[45]; st[45] = st[49]; st[49] = st[53]; st[53] = t;
			t = st[46]; st[46] = st[51]; st[51] = st[48]; st[48] = t;
			t = st[47]; st[47] = st[50]; st[50] = st[52]; st[52] = t;
			t = st[36]; st[36] = st[62]; st[62] = st[13]; st[13] = t;
			t = st[38]; st[38] = st[61]; st[61] = st[14]; st[14] = t;
			t = st[37]; st[37] = st[57]; st[57] = st[15]; st[15] = t;
			t = st[41]; st[41] = st[56]; st[56] = st[16]; st[16] = t;
			t = st[40]; st[40] = st[54]; st[54] = st[17]; st[17] = t;
			t = st[63]; st[63] = st[22]; st[22] = st[8]; st[8] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[54]; st[54] = st[58]; st[58] = st[62]; st[62] = t;
			t = st[55]; st[55] = st[60]; st[60] = st[57]; st[57] = t;
			t = st[56]; st[56] = st[59]; st[59] = st[61]; st[61] = t;
			t = st[45]; st[45] = st[71]; st[71] = st[22]; st[22] = t;
			t = st[47]; st[47] = st[70]; st[70] = st[23]; st[23] = t;
			t = st[46]; st[46] = st[66]; st[66] = st[24]; st[24] = t;
			t = st[50]; st[50] = st[65]; st[65] = st[25]; st[25] = t;
			t = st[49]; st[49] = st[63]; st[63] = st[26]; st[26] = t;
			t = st[37]; st[37] = st[31]; st[31] = st[17]; st[17] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[63]; st[63] = st[67]; st[67] = st[71]; st[71] = t;
			t = st[64]; st[64] = st[69]; st[69] = st[66]; st[66] = t;
			t = st[65]; st[65] = st[68]; st[68] = st[70]; st[70] = t;
			t = st[54]; st[54] = st[44]; st[44] = st[31]; st[31] = t;
			t = st[56]; st[56] = st[43]; st[43] = st[32]; st[32] = t;
			t = st[55]; st[55] = st[39]; st[39] = st[33]; st[33] = t;
			t = st[59]; st[59] = st[38]; st[38] = st[34]; st[34] = t;
			t = st[58]; st[58] = st[36]; st[36] = st[35]; st[35] = t;
			t = st[45]; st[45] = st[4]; st[4] = st[26]; st[26] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[19]; st[19] = st[69]; st[69] = st[48]; st[48] = t;
			t = st[20]; st[20] = st[68]; st[68] = st[52]; st[52] = t;
			t = st[21]; st[21] = st[64]; st[64] = st[51]; st[51] = t;
			t = st[28]; st[28] = st[39]; st[39] = st[15]; st[15] = t;
			t = st[32]; st[32] = st[38]; st[38] = st[16]; st[16] = t;
			t = st[33]; st[33] = st[37]; st[37] = st[12]; st[12] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[28]; st[28] = st[42]; st[42] = st[57]; st[57] = t;
			t = st[29]; st[29] = st[41]; st[41] = st[61]; st[61] = t;
			t = st[30]; st[30] = st[37]; st[37] = st[60]; st[60] = t;
			t = st[1]; st[1] = st[48]; st[48] = st[24]; st[24] = t;
			t = st[5]; st[5] = st[47]; st[47] = st[25]; st[25] = t;
			t = st[6]; st[6] = st[46]; st[46] = st[21]; st[21] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[1]; st[1] = st[51]; st[51] = st[66]; st[66] = t;
			t = st[2]; st[2] = st[50]; st[50] = st[70]; st[70] = t;
			t = st[3]; st[3] = st[46]; st[46] = st[69]; st[69] = t;
			t = st[10]; st[10] = st[57]; st[57] = st[33]; st[33] = t;
			t = st[14]; st[14] = st[56]; st[56] = st[34]; st[34] = t;
			t = st[15]; st[15] = st[55]; st[55] = st[30]; st[30] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[10]; st[10] = st[61]; st[61] = st[39]; st[39] = t;
			t = st[11]; st[11] = st[59]; st[59] = st[43]; st[43] = t;
			t = st[12]; st[12] = st[55]; st[55] = st[42]; st[42] = t;
			t = st[19]; st[19] = st[66]; st[66] = st[6]; st[6] = t;
			t = st[23]; st[23] = st[65]; st[65] = st[7]; st[7] = t;
			t = st[24]; st[24] = st[64]; st[64] = st[3]; st[3] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[10]; st[10] = st[39]; st[39] = st[61]; st[61] = t;
			t = st[11]; st[11] = st[43]; st[43] = st[59]; st[59] = t;
			t = st[12]; st[12] = st[42]; st[42] = st[55]; st[55] = t;
			t = st[19]; st[19] = st[6]; st[6] = st[66]; st[66] = t;
			t = st[23]; st[23] = st[7]; st[7] = st[65]; st[65] = t;
			t = st[24]; st[24] = st[3]; st[3] = st[64]; st[64] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[1]; st[1] = st[66]; st[66] = st[51]; st[51] = t;
			t = st[2]; st[2] = st[70]; st[70] = st[50]; st[50] = t;
			t = st[3]; st[3] = st[69]; st[69] = st[46]; st[46] = t;
			t = st[10]; st[10] = st[33]; st[33] = st[57]; st[57] = t;
			t = st[14]; st[14] = st[34]; st[34] = st[56]; st[56] = t;
			t = st[15]; st[15] = st[30]; st[30] = st[55]; st[55] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[28]; st[28] = st[57]; st[57] = st[42]; st[42] = t;
			t = st[29]; st[29] = st[61]; st[61] = st[41]; st[41] = t;
			t = st[30]; st[30] = st[60]; st[60] = st[37]; st[37] = t;
			t = st[1]; st[1] = st[24]; st[24] = st[48]; st[48] = t;
			t = st[5]; st[5] = st[25]; st[25] = st[47]; st[47] = t;
			t = st[6]; st[6] = st[21]; st[21] = st[46]; st[46] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[19]; st[19] = st[48]; st[48] = st[69]; st[69] = t;
			t = st[20]; st[20] = st[52]; st[52] = st[68]; st[68] = t;
			t = st[21]; st[21] = st[51]; st[51] = st[64]; st[64] = t;
			t = st[28]; st[28] = st[15]; st[15] = st[39]; st[39] = t;
			t = st[32]; st[32] = st[16]; st[16] = st[38]; st[38] = t;
			t = st[33]; st[33] = st[12]; st[12] = st[37]; st[37] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[63]; st[63] = st[71]; st[71] = st[67]; st[67] = t;
			t = st[64]; st[64] = st[66]; st[66] = st[69]; st[69] = t;
			t = st[65]; st[65] = st[70]; st[70] = st[68]; st[68] = t;
			t = st[54]; st[54] = st[31]; st[31] = st[44]; st[44] = t;
			t = st[56]; st[56] = st[32]; st[32] = st[43]; st[43] = t;
			t = st[55]; st[55] = st[33]; st[33] = st[39]; st[39] = t;
			t = st[59]; st[59] = st[34]; st[34] = st[38]; st[38] = t;
			t = st[58]; st[58] = st[35]; st[35] = st[36]; st[36] = t;
			t = st[45]; st[45] = st[26]; st[26] = st[4]; st[4] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[54]; st[54] = st[62]; st[62] = st[58]; st[58] = t;
			t = st[55]; st[55] = st[57]; st[57] = st[60]; st[60] = t;
			t = st[56]; st[56] = st[61]; st[61] = st[59]; st[59] = t;
			t = st[45]; st[45] = st[22]; st[22] = st[71]; st[71] = t;
			t = st[47]; st[47] = st[23]; st[23] = st[70]; st[70] = t;
			t = st[46]; st[46] = st[24]; st[24] = st[66]; st[66] = t;
			t = st[50]; st[50] = st[25]; st[25] = st[65]; st[65] = t;
			t = st[49]; st[49] = st[26]; st[26] = st[63]; st[63] = t;
			t = st[37]; st[37] = st[17]; st[17] = st[31]; st[31] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[45]; st[45] = st[53]; st[53] = st[49]; st[49] = t;
			t = st[46]; st[46] = st[48]; st[48] = st[51]; st[51] = t;
			t = st[47]; st[47] = st[52]; st[52] = st[50]; st[50] = t;
			t = st[36]; st[36] = st[13]; st[13] = st[62]; st[62] = t;
			t = st[38]; st[38] = st[14]; st[14] = st[61]; st[61] = t;
			t = st[37]; st[37] = st[15]; st[15] = st[57]; st[57] = t;
			t = st[41]; st[41] = st[16]; st[16] = st[56]; st[56] = t;
			t = st[40]; st[40] = st[17]; st[17] = st[54]; st[54] = t;
			t = st[63]; st[63] = st[8]; st[8] = st[22]; st[22] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[36]; st[36] = st[44]; st[44] = st[40]; st[40] = t;
			t = st[37]; st[37] = st[39]; st[39] = st[42]; st[42] = t;
			t = st[38]; st[38] = st[43]; st[43] = st[41]; st[41] = t;
			t = st[63]; st[63] = st[4]; st[4] = st[53]; st[53] = t;
			t = st[65]; st[65] = st[5]; st[5] = st[52]; st[52] = t;
			t = st[64]; st[64] = st[6]; st[6] = st[48]; st[48] = t;
			t = st[68]; st[68] = st[7]; st[7] = st[47]; st[47] = t;
			t = st[67]; st[67] = st[8]; st[8] = st[45]; st[45] = t;
			t = st[54]; st[54] = st[35]; st[35] = st[13]; st[13] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[27]; st[27] = st[35]; st[35] = st[31]; st[31] = t;
			t = st[28]; st[28] = st[30]; st[30] = st[33]; st[33] = t;
			t = st[29]; st[29] = st[34]; st[34] = st[32]; st[32] = t;
			t = st[0]; st[0] = st[67]; st[67] = st[26]; st[26] = t;
			t = st[2]; st[2] = st[68]; st[68] = st[25]; st[25] = t;
			t = st[1]; st[1] = st[69]; st[69] = st[21]; st[21] = t;
			t = st[5]; st[5] = st[70]; st[70] = st[20]; st[20] = t;
			t = st[4]; st[4] = st[71]; st[71] = st[18]; st[18] = t;
			t = st[9]; st[9] = st[44]; st[44] = st[58]; st[58] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[18]; st[18] = st[26]; st[26] = st[22]; st[22] = t;
			t = st[19]; st[19] = st[21]; st[21] = st[24]; st[24] = t;
			t = st[20]; st[20] = st[25]; st[25] = st[23]; st[23] = t;
			t = st[27]; st[27] = st[58]; st[58] = st[17]; st[17] = t;
			t = st[29]; st[29] = st[59]; st[59] = st[16]; st[16] = t;
			t = st[28]; st[28] = st[60]; st[60] = st[12]; st[12] = t;
			t = st[32]; st[32] = st[61]; st[61] = st[11]; st[11] = t;
			t = st[31]; st[31] = st[62]; st[62] = st[9]; st[9] = t;
			t = st[0]; st[0] = st[71]; st[71] = st[49]; st[49] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[9]; st[9] = st[17]; st[17] = st[13]; st[13] = t;
			t = st[10]; st[10] = st[12]; st[12] = st[15]; st[15] = t;
			t = st[11]; st[11] = st[16]; st[16] = st[14]; st[14] = t;
			t = st[18]; st[18] = st[49]; st[49] = st[8]; st[8] = t;
			t = st[20]; st[20] = st[50]; st[50] = st[7]; st[7] = t;
			t = st[19]; st[19] = st[51]; st[51] = st[3]; st[3] = t;
			t = st[23]; st[23] = st[52]; st[52] = st[2]; st[2] = t;
			t = st[22]; st[22] = st[53]; st[53] = st[0]; st[0] = t;
			t = st[27]; st[27] = st[62]; st[62] = st[40]; st[40] = t;
      if (dfs(st,k +1)) return true;
		}
		{
      memcpy(st, b, sizeof(b));
			t = st[0]; st[0] = st[8]; st[8] = st[4]; st[4] = t;
			t = st[1]; st[1] = st[3]; st[3] = st[6]; st[6] = t;
			t = st[2]; st[2] = st[7]; st[7] = st[5]; st[5] = t;
			t = st[9]; st[9] = st[40]; st[40] = st[35]; st[35] = t;
			t = st[11]; st[11] = st[41]; st[41] = st[34]; st[34] = t;
			t = st[10]; st[10] = st[42]; st[42] = st[30]; st[30] = t;
			t = st[14]; st[14] = st[43]; st[43] = st[29]; st[29] = t;
			t = st[13]; st[13] = st[44]; st[44] = st[27]; st[27] = t;
			t = st[18]; st[18] = st[53]; st[53] = st[67]; st[67] = t;
      if (dfs(st,k +1)) return true;
		}
    return false;
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    for (int i = 0; i < 72; i++) scanf("%d", st+i);
    if (dfs(st,0))
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }

}
