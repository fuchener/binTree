#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 11 // 最大节点数量

typedef struct TreeNode {
    int data;
} TreeNode;

TreeNode nodes[MAX_SIZE]; // 定义静态数组存储节点
int size = 0; // 已存储节点数量

void createTree() {
    int value;
    printf("请输入根节点的值：");
    scanf("%d", &value);

    if (value == -1) {
        printf("根节点不能为空！\n");
        exit(1);
    }

    nodes[0].data = value;
    size++;

    int front = 0, rear = 1;
    while (front < rear) {
        int index = front;
        front++;

        int leftChildIndex = index * 2 + 1; // 计算左子节点下标
        int rightChildIndex = index * 2 + 2; // 计算右子节点下标

        // 输入左子节点的值
        printf("请输入节点 %d 的左子节点的值（输入-1表示空节点）：", nodes[index].data);
        scanf("%d", &value);

        if (value != -1) {
            if (leftChildIndex >= MAX_SIZE) {
                printf("超过最大节点数量！\n");
                exit(1);
            }

            nodes[leftChildIndex].data = value;
            size++;
            rear = leftChildIndex + 1;
        }

        // 输入右子节点的值
        printf("请输入节点 %d 的右子节点的值（输入-1表示空节点）：", nodes[index].data);
        scanf("%d", &value);

        if (value != -1) {
            if (rightChildIndex >= MAX_SIZE) {
                printf("超过最大节点数量！\n");
                exit(1);
            }

            nodes[rightChildIndex].data = value;
            size++;
            rear = rightChildIndex + 1;
        }
    }
}

int main() {
    createTree();

    printf("二叉树创建成功！\n");

    return 0;
}
