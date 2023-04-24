#include <stdio.h>
#include <algorithm>
using namespace std;
int building_height[1004] = {0};
int main(void)
{
    for(int i=0; i<10; i++){
        int n;
        int result = 0;
        scanf("%d", &n);
        scanf("%d %d %d %d", &building_height[0], &building_height[1], &building_height[2], &building_height[3]);
        for(int j=4; j<n; j++){ // for all building
            scanf("%d", &building_height[j]);
            int maximum_height = max({building_height[j-4], building_height[j-3], building_height[j-1], building_height[j]});
            if (building_height[j-2] > maximum_height)
                result += (building_height[j-2] - maximum_height);
        }
        printf("#%d %d\n", i+1, result);
    }
    return 0;
}