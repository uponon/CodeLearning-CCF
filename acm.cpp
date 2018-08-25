#include <bits/stdc++.h>
using namespace std;
/***********************class**********************************/
class Action {
    public:
        int room;//Կ�׺�
        int time;//�黹�¼�������ʱ��
        int type;// 0:��Կ��, 1:��Կ��
        //���캯������ʼ���б�������ĳ�ʼ�� 
        Action(int room_,int time_,int type_):room(room_),time(time_),type(type_){}
/********************����operator<���� *******************************/      
        bool operator<(const Action &other) const 
        {
            if(time<other.time) return true;
            else if(time==other.time && type<other.type) return true;
            else if(time==other.time && type==other.type && room<other.room) return true;
            return false;
        }
};
/*********************��дoperator<���� ******************
С�ں�ʱ�������� 
int cmp(Action action1,Action action2)
{
    if(action1.time<action2.time)
    {
        return 1;
    }
    else if(action1.time == action2.time && action1.type < action2.type)
    {
        return 1;
    }
    else if(action1.time == action2.time && action1.type == action2.type&& action1.room < action2.room)
    {
            return 1;   
    }
    return 0;
}
*/
int main() {
    int N, K;
    cin>>N>>K;
    //����Action���͵�Vector���� 
    vector<Action> actions;
    //Կ�׵ĳ�ʼ������ 
    vector<int> result(N+1);
    for(int n=1;n<=N; n++) result[n] = n;
    for(int k=0;k<K; k++) 
    {
        int room, begin, length;
        cin>>room>>begin>>length;
        actions.push_back(Action(room, begin, 1));//��Կ�� 
        actions.push_back(Action(room, begin+length, 0));
    }
/*************sort����operator<��д������������ ******************/
    sort(actions.begin(),actions.end());
/***********************ȡ�Ų���**********************************/   
    for(int i=0;i<actions.size();i++) 
    {
        Action &act = actions[i];//����(����) 
        if(act.type == 0) //put�ţ��� 
        { 
            for(int n=1; n<=N; n++) 
            {
                if(result[n] == -1) 
                {
                    result[n] = act.room;
                    break;
                }
            }
        }
        else //getȡ���ȣ�
        { 
            for(int n=1; n<=N; n++) 
            {
                if(result[n] == act.room) 
                {
                    result[n] = -1;
                    break;
                }
            }
        }
    }
/***********************������**********************************/   
    for(int n=1; n<=N; n++) 
    {
        cout<<result[n]<<" ";
    }
}