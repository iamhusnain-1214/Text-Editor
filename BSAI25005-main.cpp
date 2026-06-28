
#include "BSAI25005-Document.h"
#include "raylib.h"
struct Layout
{
    float padding = 20;
    float lineNumberWidth = 60;
    float statusBarHeight = 30;
};
struct Theme
{
    Color background = { 46, 52, 64, 255 };
    Color lineNumberBg = { 59, 66, 82, 255 };
    Color currentLine = { 67, 76, 94, 255 };
    Color text = { 216, 222, 233, 255 };
    Color lineNumber = { 136, 192, 208, 255 };
    Color cursor = { 136, 192, 208, 255 };
    Color statusBar = { 20, 184, 166, 255 };
};
int main()
{
    InitWindow(1900, 1080, "My Editor Phase 1");
    SetTargetFPS(60);
    Font font = LoadFont("Myfont.ttf");
    Document doc;

    while (!WindowShouldClose())
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if (key >= 32 and key <= 126)
                doc.insertCharacter((char)key);

            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_ENTER))
            doc.insertNewLine();

        BeginDrawing();

        Theme theme;
        Layout layout;

        float windowWidth = GetScreenWidth();
        float windowHeight = GetScreenHeight();
        float editorHeight = windowHeight - layout.statusBarHeight;
        ClearBackground(theme.background);
        DrawRectangle(0, 0,layout.lineNumberWidth, editorHeight, theme.lineNumberBg);
        DrawRectangle(0, editorHeight,windowWidth,layout.statusBarHeight,theme.statusBar);
        DrawText(TextFormat("Line: %i | Col: %i",  doc.cri + 1,  doc.cci + 1), 10, editorHeight + 5, 20,WHITE);
        doc.draw(font);
        EndDrawing();
    }
    UnloadFont(font);
    CloseWindow();
}