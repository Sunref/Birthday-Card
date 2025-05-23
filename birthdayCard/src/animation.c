#include "animation.h"
#include "../include/config.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

// Maximum length for messages
#define MAX_MESSAGE_LENGTH 256

// Structure to hold messages
typedef struct {
    char main[MAX_MESSAGE_LENGTH];
    char sub[MAX_MESSAGE_LENGTH];
    char third[MAX_MESSAGE_LENGTH];
    bool loaded;
} Messages;

// Static messages container
static Messages messages = {
    .main = MAIN_MESSAGE,    // Default message if file not found
    .sub = SUB_MESSAGE,      // Default message if file not found
    .third = THIRD_MESSAGE,  // Default message if file not found
    .loaded = false
};

// Load messages from file
static void LoadMessages() {
    if (!messages.loaded) {
        FILE* configFile = fopen("messages.txt", "r");
        if (configFile != NULL) {
            // Read messages
            if (fgets(messages.main, sizeof(messages.main), configFile) != NULL) {
                messages.main[strcspn(messages.main, "\n")] = 0;  // Remove newline
            }
            if (fgets(messages.sub, sizeof(messages.sub), configFile) != NULL) {
                messages.sub[strcspn(messages.sub, "\n")] = 0;  // Remove newline
            }
            if (fgets(messages.third, sizeof(messages.third), configFile) != NULL) {
                messages.third[strcspn(messages.third, "\n")] = 0;  // Remove newline
            }
            fclose(configFile);
        }
        messages.loaded = true;
    }
}

// Draw birthday message with animated color effects
void DrawAnimatedText(float time) {
    // Load messages if not already loaded
    LoadMessages();

    // Calculate text widths for centering
    int textWidth = MeasureText(messages.main, MAIN_FONT_SIZE);
    int textWidth2 = MeasureText(messages.sub, SUB_FONT_SIZE);
    int textWidth3 = MeasureText(messages.third, THIRD_FONT_SIZE);

    // Generate pulsating colors based on time
    Color textColor = (Color){
        (unsigned char)(255 * fabs(sin(time * 0.5f))),
        (unsigned char)(255 * fabs(sin(time * 0.3f + 2))),
        (unsigned char)(255 * fabs(sin(time * 0.2f + 4))),
        255
    };

    Color textColor2 = (Color){
        (unsigned char)(255 * fabs(sin(time * 0.5f + 1))),
        (unsigned char)(255 * fabs(sin(time * 0.3f + 3))),
        (unsigned char)(255 * fabs(sin(time * 0.2f + 5))),
        255
    };

    Color textColor3 = (Color){
        (unsigned char)(255 * fabs(sin(time * 0.5f + 1))),
        (unsigned char)(255 * fabs(sin(time * 0.3f + 3))),
        (unsigned char)(255 * fabs(sin(time * 0.2f + 5))),
        255
    };

    // Draw main message with shadow
    DrawText(
        messages.main,
        SCREEN_WIDTH/2 - textWidth/2 + 3,
        SCREEN_HEIGHT/2 - 30 + 3,
        MAIN_FONT_SIZE,
        BLACK
    );

    DrawText(
        messages.main,
        SCREEN_WIDTH/2 - textWidth/2,
        SCREEN_HEIGHT/2 - 30,
        MAIN_FONT_SIZE,
        textColor
    );

    // Draw second message with shadow
    DrawText(
        messages.sub,
        SCREEN_WIDTH/2 - textWidth2/2 + 2,
        SCREEN_HEIGHT/2 + 40 + 2,
        SUB_FONT_SIZE,
        BLACK
    );

    DrawText(
        messages.sub,
        SCREEN_WIDTH/2 - textWidth2/2,
        SCREEN_HEIGHT/2 + 40,
        SUB_FONT_SIZE,
        textColor2
    );

    // Draw third message with shadow
    DrawText(
        messages.third,
        SCREEN_WIDTH/2 - textWidth3/2 + 2,
        SCREEN_HEIGHT/2 + 80 + 2,
        THIRD_FONT_SIZE,
        BLACK
    );

    DrawText(
        messages.third,
        SCREEN_WIDTH/2 - textWidth3/2,
        SCREEN_HEIGHT/2 + 80,
        THIRD_FONT_SIZE,
        textColor3
    );
}
