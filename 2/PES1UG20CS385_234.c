//SANMAT SANJAYAKUMAR PAYAGOUDAR
//PES1UG20CS385
#include "header.h"
#includecd<limits.h>
#include<stdlib.h>
#include<stdio.h>

//any static functions are up here

static void q1_dfs (int x , int visite[] , int n , const connecn_t grp[n][n])
{
    visite[x] = 1;
    for(int r = x ; r < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (grp[r][j].dist != __INT_MAX__ && visite[j]!= 1)
            {
                q1_dfs(j , visite , n , grp);
            }
        }
    }
}

static int chk(int visite[] , int n)
{

    for (int m = 0 ; m < n ; i++)
    {
        if (visite[m] != 1)
        {
            return 0;
        }
        visite[m] = 0;
    }
    return 1;
}

static void q2_dfs (int x , int visite[] , int n , const connecn_t grp[n][n] , int dest , int num , int *answer)
{
    visite[x] = 1;
    if (x == dest)
    {
        
        int flg = 0;
        for (int i  = 0 ; i < n ; i++)
        {
            if (visite[i] == 1)
            {
                flg ++;
            }
        }
        if (flg <= num+1)
        {
            *answer = 1;
        }
    }
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (grp[i][j].dist != __INT_MAX__ && visite[j]!= 1)
            {
               q2_dfs(j , visite , n , grp , dest , num , answer);
            }
        }
    }

}

static void q3_dfs (int x , int visite[] , int n , const connecn_t matrix[n][n] , int src , int *answer)
{
    visite[x] = 1;
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (matrix[i][j].dist != __INT_MAX__ && j == src)
            {
                *answer = 1;
            }
            if (matrix[i][j].dist != __INT_MAX__ && visite[j]!= 1)
            {
                q3_dfs(j , visite , n , matrix , src , answer);
            } 
        }
    }
}

static void swap(AirPort_t *a, AirPort_t *b)
{
    AirPort_t t = *a;
    *a = *b;
    *b = t;
}

static int partition(AirPort_t array[], int start, int end, int (*predicate_function)(const AirPort_t *, const AirPort_t *))
{
    int p_index = start;
    AirPort_t pivot = array[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(predicate_function(&array[i] , &pivot))
        {
            swap(&array[i], &array[p_index]);
            p_index++;
        }
    }
    swap(&array[end], &array[p_index]);
    return p_index;
}

static void quick_sort(AirPort_t array[], int start, int end,int (*predicate_function)(const AirPort_t *, const AirPort_t *) )
{
    if(start < end)
    {
        int qIndex = partition(array, start, end,predicate_function);
        quick_sort(array, start, qIndex-1,predicate_function);
        quick_sort(array, qIndex+1, end,predicate_function);
    }
}

static int length(AirPort_t airport1,AirPort_t airport2)
{
    int h=0;
    while(AirPort1.AirPort_name[h]!='\0' && AirPort2.AirPort_name[h]!='\0' && AirPort1.AirPort_name[h] == AirPort2.AirPort_name[h])
    {
        h++;
    }
    return h;
}

static void shift_table(const char p[],int t[])
{
    int i,j,m=0;
    for(int x = 0 ; p[x] != '\0';x++)
        m++;
    for(i=0;i<500;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]-'0']=m-1-j;
}

static int horspool(const char source[],const char p[],int t[])
{
    int i,k,m=0,n=0;
    for(int x = 0 ; p[x] != '\0';x++)
        m++;
    for(int x = 0 ; source[x] != '\0';x++)
        n++;
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m)&&(p[m-1-k]==source[i-k]))
        k++;
        if(k==m)
        return(i-m+1);
        else
        i+=t[source[i]-'0'];
    }
    return -1;
}

static int min_key(int V,int key[], int mst_set[])
{

    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mst_set[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

static void make_MST(int V,int parent[], const connecn_t grp[V][V],pair_t edges[V - 1])
{
    for (int i = 1; i < V; i++)
    {    
        edges[i-1].first = parent[i];
        edges[i-1].second = i;
    }
}

static int min_itime(int n,pair_t edges[],const connecn_t grp[n][n],int parent[])
{
    int res = 0;
    for(int i=0;i<n-1;i++)
        res = res + grp[edges[i].first][edges[i].second].time;
    return res;
}
 
static void Dijkstra(int n,const connecn_t grp[n][n], int start,int *hash) {
  int cst[n][n], dist[n], pred[n];
  int visited[n], cnt, mind_istance, next_node, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (grp[i][j].time == 0)
        cst[i][j] = INT_MAX;
      else
        cst[i][j] = grp[i][j].time;

  for (i = 0; i < n; i++) {
    dist[i] = cst[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  dist[start] = 0;
  visited[start] = 1;
  cnt = 1;

  while (cnt < n - 1) {
    mind_istance = INT_MAX;

    for (i = 0; i < n; i++)
      if (dist[i] < mind_istance && !visited[i]) {
        mind_istance = dist[i];
        next_node = i;
      }

    visited[next_node] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mind_istance + cst[next_node][i] < dist[i]) {
          dist[i] = mind_istance + cst[next_node][i];
          pred[i] = next_node;
        }
    cnt++;
  }

  for (i = 0; i < n; i++)
    if (i != start) {
       hash[i]  = dist[i];
    }
}

//your solutions below

int q1(int n, const connecn_t connecns[n][n])
{
    int visite[100000];

    for(int i = 0 ; i < n ; i++)
    {
        visite[i] = 0;
    }
    int answer = 1;

    for (int i = 0 ; i < n ; i++)
    {
        q1_dfs(i , visite , n , connecns);
        answer = answer & chk(visite , n);
    }
    return answer;

}

int q2(const AirPort_t *source, const AirPort_t *dest, int n, int k,const connecn_t connecns[n][n])
{
    int sval = source->number_id;
    int dval = dest->number_id;
    int visite[100000];
    int answer = 0;
    for(int i = 0 ; i < n ; i++)
    {
        visite[i] = 0;
    }
    q2_dfs(sval , visite , n , connecns , dval , k , &answer);
    if(answer == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int q3(const AirPort_t *source, int n, const connecn_t connecns[n][n])
{
    int src = source->number_id;
    int visite[100000];
    int answer = 0;
    for(int i = 0 ; i < n ; i++)
    {
        visite[i] = 0;
    }
    q3_dfs(src , visite , n , connecns, src , &answer);
    return answer;
}

void q4(int n, int (*predicate_function)(const AirPort_t *, const AirPort_t *),AirPort_t airport_list[n])
{
    quick_sort(airport_list,0,n-1,predicate_function);
}

pair_t q5(int n, AirPort_t airports[n])
{
    pair_t answer = {-1, -1};
    int maximum = 0;
    int a;
    for(int i=0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            a = length(airports[i],airports[j]);
            if(maximum < a)
            {
                maximum = a;
                answer.first = airports[i].number_id;
                answer.second = airports[j].number_id;
            }
        }
    }
    return answer;

}

int q6(int n, int amt, const int entryFee[n])
{
        int si=0, ei=n-1;
        int mid;
        while(si <= ei) {

            mid = si + (ei-si)/2; 


            if(entryFee[mid] == amt) {
                return mid+1;
            } else if(entryFee[mid] < amt) {
                si = mid+1;
            } else { 
                ei = mid-1;
            }
        }

        return si;
}

void q7(int n, const char *pat, int contains[n], const AirPort_t airports[n])
{
    for(int i = 0;i<n;i++)
    {
        int t[500] = {0};
        shift_table(pat,t);
        if(horspool(airports[i].airport_name,pat,t)>=0)
        {
            contains[i] = 1;
        }
    }
}

int q8(int n, int trip_order[n - 1], const connecn_t connecns[n][n])
{
    int trip_num[n][n-1];
    connecn_t connecn[n][n];
    int a[n-2], path[n-1];
    int min_length=INT_MAX, length=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
				if(j<i)
				{
					trip_num[i][j]=j;
				}
				else
				{
					trip_num[i][j-1]=j;
				}
            }
        }
    }
    for(int j=0;j<n;j++)
    {
		for(int i=0;i<n-2;i++)
		{
			a[i]=trip_num[j][i+1];
		}
		path[0]=trip_num[j][0];
		jt(a,a,n-2,n-2, &length,connecns,path);
		if(length<min_length)
		{
			min_length=length;
			for(int l=0;l<n-1;l++)
			{
				trip_order[l]=path[l];
			}
		}
    }
    if(min_length==INT_MAX)
		min_length=-1;
    return min_length;
}

int q9(int n, pair_t edges[n - 1], const connecn_t connecns[n][n])
{
    int parent[n];

    int key[n];

    int mst_set[n];
 

    for (int i = 1; i < n; i++)
        key[i] = INT_MAX, mst_set[i] = 0;
 

    key[0] = 0;
    parent[0] = -1;
 
    for (int cnt = 0; cnt < n - 1; cnt++) {

        int u = min_key(n,key, mst_set);
 
        mst_set[u] = 1;
 
        for (int v = 0; v < n; v++)
 
            if (connecns[u][v].time && mst_set[v] == 0 && connecns[u][v].time < key[v])
                parent[v] = u, key[v] = connecns[u][v].time;
    }
 
    make_MST(n,parent, connecns ,edges);

    return min_itime(n,edges,connecns,parent);
}

void q10(int n, int k, const AirPort_t *source, const connecn_t connecns[n][n], const int destinations[k],int costs[k])
{
    int hash[n];
    Dijkstra(n,connecns,source->number_id,hash);
    int i=0;
    while(i!=k)
    {
        costs[i] = hash[destinations[i]];
        i++;
    }
}

// END