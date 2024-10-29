#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node {  
    int priority;
    int index;
    
};

bool operator<(node a, node b)  {
        if (a.priority != b.priority)  
            return a.priority < b.priority;
        return a.index > b.index;
    }


int main() {
    int n;
    while (~scanf("%d", &n)) {
        priority_queue<node> que[4];
        int cc = 1;
        for (int i = 0; i < n; ++i) {
            char str[10];
            scanf("%s", str);

            if (!strcmp(str, "IN")) {
                node temp;
                temp.index = cc++;

                int doctor_index;
                int priority;
                scanf("%d%d", &doctor_index, &priority);
                temp.priority = priority;

                que[doctor_index].push(temp);
            }

            else if (!strcmp(str, "OUT")) {
                int doctor_index;
                scanf("%d", &doctor_index);
                if (que[doctor_index].empty() == false) {
                    printf("%d\n", que[doctor_index].top().index);
                    que[doctor_index].pop();
                } else
                    printf("EMPTY\n");
            }
        }
    }
    return 0;
}