#include <stdio.h>
#include <stdbool.h>

//<lihf> Ҫע����ǣ��ں�����ʹ�ô��ι����Ķ�ά���飨ָ�룩��������ȡֵ��ʱ����ʹ�ã�array[i][j]��������ʽ��ȡֵ��
//       Ӧ�ý���ά���鿴��һ��һά���飬ʹ��array[i * j + j]������ʽ������ȡֵ��
static bool find_num(int *src_array, int rows, int cols, int dest_num)
{
    int cols_tmp = cols;
    
    if( (NULL == src_array) || (0 == rows) || (0 == cols) )
    {
        printf("input error!");
    }
        
    for(int i=0; i<rows; i++)
    {
        if(dest_num <= src_array[i*cols_tmp + (cols-1)])
        {
            if(dest_num < src_array[i*cols_tmp])
            {
                //<lihf> С����Ԫ�أ�����Ҫ������
                printf("num: %d is not in the array\n", dest_num);
                return false;
            }
            
            for(int j=0; j<cols; j++)
            {
                if(dest_num == src_array[i*cols_tmp + j])
                {
                    printf("num: %d is in the array\n", dest_num);
                    return true;
                }
            }
            
            cols--;  //<lihf> ��С��һ�м�鷶Χ
        }
    }
    
    printf("num: %d is not in the array\n", dest_num);
    return false;
}

int main(void)
{
    int num[5][5] = {{1,  4,  7,  11, 15}, \
                     {2,  5,  8,  12, 19}, \
                     {3,  6,  9,  16, 22}, \
                     {10, 13, 14, 17, 24}, \
                     {18, 21, 23, 26, 30}  \
                    };
    int input;
    
    int rows = sizeof(num) / sizeof(num[0]);
    int clos = sizeof(num[0]) / sizeof(num[0][0]);
    
    while(1)
    {
        printf("Input the num:");
        scanf("%d", &input);
        
        if(0 == input)
        {
            break;
        }
        
        find_num((int *)&num[0][0], rows, clos, input);
        printf("\n");
    }
    
    return 0;
}