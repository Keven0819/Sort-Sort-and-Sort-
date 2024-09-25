#include <stdio.h>

int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m); 

        // 輸入 0 0 結束程式
        if (n == 0 && m == 0) {
            printf("0 0\n");
            break; 
        }
        printf("%d %d\n", n, m);

        // n 輸入多少，陣列就有幾個數
        int arr[n];

        // 從陣列索引 0 ~ n - 1，輸入值
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // 每個數都要對比一次，所以要兩個迴圈
        for (int i = 0; i < n; i++) { 

            // 從索引 i + 1 開始，對比索引 i 的值
            for (int j = i + 1; j < n; j++) {

                // 題目給的條件，餘數相同，一奇一偶，奇數在前，偶數在後，兩奇數大的在前小的在後，偶數小的在前大的在後
                if ((arr[i] % m > arr[j] % m) || 
                (arr[i] % m == arr[j] % m && arr[i] % 2 == 0 && arr[j] % 2 != 0) || 
                (arr[i] % m == arr[j] % m && arr[i] % 2 == arr[j] % 2 && 
                ((arr[i] % 2 != 0 && arr[i] < arr[j]) || (arr[i] % 2 == 0 && arr[i] > arr[j])))) {

                    // 兩數交換
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        // 印出排序後的陣列
        for (int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
    }
    return 0;
}