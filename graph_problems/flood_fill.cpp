/*
 * Given a 2D screen, location of the pixel and new value of the color to fill, replace the color of the
 * pixel and all the adjacent(up, below, left, right) same colored pixel with new color.
 * 
 * This is same as flood fill (remember the bucket symbol) a region in MS-PAINT.
 * 
 * [[1 1 1 2 2 1 1]
 *  [1 1 1 2 1 1 1]
 *  [1 2 2 2 1 3 3]
 *  [4 4 1 2 7 9 9]]
 * 
 * The screen is 0-indexed.
 * Start at pixel (1, 3) and replace color 2 with color 5, in this pixel and all the adjacent same
 * color pixels.
 * 
 * Therefore, the answer would be:
 * [[1 1 1 5 5 1 1]
 *  [1 1 1 5 1 1 1]
 *  [1 5 5 5 1 3 3]
 *  [4 4 1 5 7 9 9]]
 * 
 * Approach: Use the simple depth first search to search adjacent pixels of same color
 * and mark them with new color. 
 */

#include <iostream>
#include <vector>

bool is_valid(int grid_height, int grid_width, int sr, int sc) {
    return (sr >= 0 && sr < grid_height && sc >= 0 &&
        sc < grid_width); 
}

void flood_fill_helper(std::vector<std::vector<int>>& image, int sr, int sc, int new_color, int old_color)
{
    if (!is_valid(image.size(), image[0].size(), sr, sc)) {
        return;
    }

    if (image[sr][sc] != old_color) {
        return;
    }

    image[sr][sc] = new_color;
    flood_fill_helper(image, sr - 1, sc, new_color, old_color);
    flood_fill_helper(image, sr + 1, sc, new_color, old_color);
    flood_fill_helper(image, sr, sc - 1, new_color, old_color);
    flood_fill_helper(image, sr, sc + 1, new_color, old_color);
}

std::vector<std::vector<int>> flood_fill(std::vector<std::vector<int>>& image, int sr, int sc, int new_color)
{
    if (image[sr][sc] != new_color) {
        int old_color = image[sr][sc];
        flood_fill_helper(image, sr, sc, new_color, old_color);
    }
    return image;
}

void print_image(const std::vector<std::vector<int>>& image) {
    for (auto row : image) {
        for (auto pixel : row) {
            std::cout << pixel << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> image = {
        {1, 1, 1, 2, 2, 1, 1},
        {1, 1, 1, 2, 1, 1, 1},
        {1, 2, 2, 2, 1, 3, 3},
        {4, 4, 1, 2, 7, 9, 9}
    };
    std::cout << "Current Image:" << std::endl;
    print_image(image);
    std::cout << "Applying flood fill at pixel (1,3) to change color to 5:" << std::endl;
    image = flood_fill(image, 1, 3, 5);
    print_image(image);
    return 0;
}