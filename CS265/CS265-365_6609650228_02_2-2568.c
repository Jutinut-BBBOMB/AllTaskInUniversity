///นายจุติณัฏฐ์ รัตนะมงคลกุล 6609650228

#include <stdio.h>
#include <string.h>

struct Room {
    char name[2];       
    char status[10];    
};


void cleanRoom(struct Room *room) {
    if (strcmp(room->status, "Dirty") == 0) {
        strcpy(room->status, "Clean");
        printf("Cleaning room %s...\n", room->name);
    } else {
        printf("Room %s is already clean.\n", room->name);
    }
}


void reflexVacuumAgent(struct Room *room) {
    if (strcmp(room->status, "Dirty") == 0) {
        cleanRoom(room);
    } else {
        printf("Moving from room %s to ", room->name);
        if (strcmp(room->name, "A") == 0) printf("B\n");
        else if (strcmp(room->name, "B") == 0) printf("E\n");
        else if (strcmp(room->name, "E") == 0) printf("F\n");
        else if (strcmp(room->name, "F") == 0) printf("D\n");
        else if (strcmp(room->name, "D") == 0) printf("C\n");
        else if (strcmp(room->name, "C") == 0) printf("A\n");
    }
}


void displayRooms(struct Room rooms[], int size) {
    printf("\nCurrent room status:\n");
    for (int i = 0; i < size; i++) {
        printf("Room %s: %s\n", rooms[i].name, rooms[i].status);
    }
}

int main() {
    
    struct Room rooms[] = {
        {"A", "Dirty"},
        {"B", "Clean"},
        {"C", "Dirty"},
        {"D", "Clean"},
        {"E", "Dirty"},
        {"F", "Clean"}
    };

    int size = sizeof(rooms) / sizeof(rooms[0]);

    
    displayRooms(rooms, size);

    
    printf("\nStart!\n");
    for (int i = 0; i < size; i++) {
        reflexVacuumAgent(&rooms[i]);  
    }

    
    displayRooms(rooms, size);

    return 0;
}
