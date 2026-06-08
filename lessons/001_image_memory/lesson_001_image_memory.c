#include <stdlib.h>
#include <stdio.h>


typedef struct
{
    int width;
    int height;
    unsigned char* data;
} Image;

int main()
{
    
    Image img = { .width = 640, .height = 480, .data = NULL };
    printf("Image width: %d, height: %d\n", img.width, img.height);

    printf("Stack Memory Addresses : There are memory locations reserved to store the image metadata\n");    
    printf("img address = %p\n", &img);
    printf("img.data address = %p\n", &img.data);
    printf("img.width address = %p\n", &img.width);   
    printf("img.height address = %p\n", &img.height);   
  
    img.data = malloc(img.width * img.height);
    printf("img.data value = %p\n", img.data);

    for (int i = 0; i < img.width * img.height; i++)
    {
        img.data[i] = 0; // Initialize pixel data to black  
    }


    return 0;
}