#include <avr/io.h>

#define LINE_SIZE 16
#define LINE_N 2
#define INPUT_N 4

typedef enum _lcd_input_e
{
  input_none=0, input_home=1, input_ok=2, input_incr=3, input_decr=4,
} LCDInput;

typedef struct _lcd_node_s
{
  uint8_t pos;
  enum _lcd_print_type_e
  {
    node_null=0, node_print_Pstr, node_print_vstr, node_print_hhmm,
    node_print_hhmmss, node_print_temp, node_print_perc, node_edit_hhmm,
    node_edit_hhmmss, node_edit_temp, node_edit_perc, node_set_menu,
  } type;
  union _lcd_pointer_u
  {
    PGR_P s;
    void *v;
    void *prog();
  } ptr;
} LCDNode;

extern PGR_P *g_status_string;
extern RTCtime g_curr_time;
extern RTCtime g_timer_on;
extern RTCtime g_timer_off;
extern uint8_t g_dtemp;
extern uint8_t g_crtemp;
extern uint8_t g_dhumd;
extern uint8_t g_dimmer_on;
extern uint8_t g_dimmer_off;

// Public functions:

void lcd_init(void);
void lcd_update(void);
void lcd_refresh(void);
void lcd_input(LCDInput);

// Application specific:

extern void lcd_send_data(uint8_t, uint8_t);
