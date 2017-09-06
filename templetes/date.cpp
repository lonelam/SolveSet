int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{
 int year,month,day;
};
//是否闰年
inline bool isleap(int year)
{
  return  (year%4==0&&year%100!=0)||year%400==0;
}
//判合法性
inline bool islegal(date a){
 if (a.month<0||a.month>12) return 0;
 if (a.month==2)
   return a.day>0&&a.day<=28+isleap(a.year);
 return a.day>0&&a.day<=days[a.month-1];
}
//比较日期大小, 正/负表示大于/小于, 0表示相等
//如果用于sort等, 请把-改成<
inline int datecmp(date a,date b){
 if (a.year!=b.year)
   return a.year-b.year;
 if (a.month!=b.month)
   return a.month-b.month;
 return a.day-b.day;
}
//日期转天数偏移({0,1,1}第1天)
int date2int(date a){
 int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;
 days[1]+=isleap(a.year);
 for (i=0;i<a.month-1;ret+=days[i++]);
 days[1]=28;
 return ret+a.day;
}
//天数偏移转日期
date int2date(int a){
 date ret;
 ret.year=a/146097*400;
 for (a%=146097;a>=365+isleap(ret.year);a-=365+isleap(ret.year),ret.year++);
 days[1]+=isleap(ret.year);
 for (ret.month=1;a>=days[ret.month-1];a-=days[ret.month-1],ret.month++);
 days[1]=28;
 ret.day=a+1;
 return ret;
}
