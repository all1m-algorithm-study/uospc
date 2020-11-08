#include <iostream>
#define ELEVATOR_MAX 5
#define FLOOR_MAX 50
#define STAIR_COST 10
#define ELEVATOR_COST 5

bool ableToGo[ELEVATOR_MAX][FLOOR_MAX + 1];
int currentPos[ELEVATOR_MAX];
int F, E, G, minTime;
bool visited[FLOOR_MAX + 1];

void ElevatorDFS(int time, int start)
{
    if (time >= minTime)
        return;

    if (start == G)
    {
        minTime = time;
        return;
    }

    visited[start] = true;

    for (int i = 0; i < E; ++i)
    {
        // 이 층에서 i번 엘리베이터를 사용할 수 있을 때
        if (ableToGo[i][start])
        {
            // 그 엘리베이터를 이용하여 갈 수 있는 모든 층을 탐색
            for (int j = F; j >= 1; --j)
            {
                if (ableToGo[i][j] && j != start && !visited[j])
                {
                    int prevPos = currentPos[i];
                    currentPos[i] = j;
                    ElevatorDFS(time + (std::abs(start - prevPos) + std::abs(start - j)) * ELEVATOR_COST, j);
                    currentPos[i] = prevPos;
                }
            }
        }
    }

    if (start < F && !visited[start + 1])
    {
        ElevatorDFS(time + STAIR_COST, start + 1);
    }

    if (start > 1 && !visited[start - 1])
    {
        ElevatorDFS(time + STAIR_COST, start - 1);
    }

    visited[start] = false;
}

int main()
{
    scanf("%d %d %d", &F, &E, &G);

    for (int i = 0; i < E; ++i)
    {
        scanf("%d", &currentPos[i]);

        int availCount;
        scanf("%d", &availCount);

        for (int j = 0; j < availCount; ++j)
        {
            int avail;
            scanf("%d", &avail);
            ableToGo[i][avail] = true;
        }
    }

    minTime = (G - 1) * STAIR_COST;

    ElevatorDFS(0, 1);

    printf("%d", minTime);

    return 0;
}