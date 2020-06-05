#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
class subtask{
public:
    int task_no;
    int arrive_time;
    int process_time;
    int prior;
    subtask(int no, int arr, int proc, int pri)
    {
        task_no = no;
        arrive_time = arr;
        process_time = proc;
        prior = pri;
    }
};
using namespace std;
main()
{
    int task;
    while(cin >> task)
    {
        int A[task + 5];
        int arrive_time, process_time, prior;
        vector <subtask> V;
        for(int i=0;i<task;i++)
        {
            A[i] = 0;
            cin >> arrive_time >> process_time >> prior;
            V.push_back(subtask(i,arrive_time,process_time,prior)); //
        }
        queue <subtask> Q[2]; //High Q = Q[0], Low Q = Q[1]
        for(int i=0;i<task;i++)
        {
            subtask k = V[i];
            Q[k.prior].push(k); //Push to relative queue.
        }
        int time_elapse = 0;
        while(!Q[0].empty() && !Q[1].empty()) //When both queues are not empty.
        {
            subtask high_prior = Q[0].front();
            int high_arr = high_prior.arrive_time;
            subtask low_prior = Q[1].front();
            int low_arr = low_prior.arrive_time;
            if(high_arr> time_elapse && low_arr > time_elapse ) //If time_elapse doesn't reach both jobs --> Both jobs not arrived yet --> skip to the job that comes first
                time_elapse = min(low_arr,high_arr);
            if(time_elapse >= high_arr) //If time reach higher priority jobs --> DO IT!
            {
                time_elapse += high_prior.process_time;
                Q[0].pop();
                A[high_prior.task_no] = time_elapse; //"Save" when job finished
            }
            else //IF time doesn't reach higher priority jobs yet --> Do the lower one.
            {
                time_elapse += low_prior.process_time;
                Q[1].pop();
                A[low_prior.task_no] = time_elapse;//"Save" when job finished
            }
        }
        while(!Q[0].empty()) //Emptying the remaining jobs in higher queue.
        {
            subtask high_prior = Q[0].front();
            int high_arr = high_prior.arrive_time;
            time_elapse = max(time_elapse, high_arr);
            time_elapse += high_prior.process_time;
            Q[0].pop();
            A[high_prior.task_no] = time_elapse;
        }
        while(!Q[1].empty()) //Emptying the remaining jobs in lower queue.
        {
            subtask low_prior = Q[1].front();
            int low_arr = low_prior.arrive_time;
            time_elapse = max(time_elapse, low_arr);
            time_elapse += low_prior.process_time;
            Q[1].pop();
            A[low_prior.task_no] = time_elapse;
        }
        for(int i=0;i<task;i++)
        {
            cout << A[i];
            if(i != task-1)
                cout <<" ";
        }
        cout << endl;
    }
}
