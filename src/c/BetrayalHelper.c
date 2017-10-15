#include <pebble.h>
#include "characters.h"
#define TITLE_HEIGHT 20
#define NUM_MENU_SECTIONS 1
#define REVERSE_TRACK 1

#define FONT_OFFSET_FACTOR 16

static Window *s_window;
static TextLayer *s_name_layer;
static MenuLayer* s_layers[NUM_TRAITS];
static int s_current_char_index = 0;
static Character* s_current_char;
static GBitmap *s_image;
static BitmapLayer *s_image_layer;
static GFont s_font, s_font_bold;

void change_character();

/* Callbacks for the menu layers. */
static uint16_t menu_get_num_sections_callback(MenuLayer *menu_layer, void *data) {
  return NUM_MENU_SECTIONS;
}

static uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return TRACK_LENGTH;
}

static int16_t menu_get_cell_height_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context) {
  if (menu_layer_is_index_selected(menu_layer, cell_index)){
    return 30;
  } else {   
    return 18;
  }
}

int get_track_index(int cell_index){
  if(REVERSE_TRACK)
    return TRACK_LENGTH - 1 - cell_index;
  else
    return cell_index;
}

static void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  int trait_index = *((int*) data);
  //TODO: Add skull icon for index 0
  GRect rect = layer_get_bounds(cell_layer);
  // vertically center the number
  rect.origin.y = rect.size.h / 2 - FONT_OFFSET_FACTOR;
  
  if( get_track_index(cell_index->row) == s_current_char->default_index[trait_index]){
    graphics_draw_text(ctx, 
                       s_current_char->trait_array[trait_index][get_track_index(cell_index->row)],
                       s_font_bold,
                       rect,
                       GTextOverflowModeFill, 
                       GTextAlignmentCenter, 
                       NULL);
  } else {
    graphics_draw_text(ctx, 
                       s_current_char->trait_array[trait_index][get_track_index(cell_index->row)],
                       s_font,
                       rect,
                       GTextOverflowModeFill, 
                       GTextAlignmentCenter, 
                       NULL);
  }
}

void set_active_track(int *new_track, int *old_track){
  menu_layer_set_click_config_onto_window(s_layers[*new_track], s_window);
  menu_layer_set_highlight_colors(s_layers[*new_track], s_current_char->background_color, s_current_char->text_color);
  layer_mark_dirty(menu_layer_get_layer(s_layers[*new_track]));
  if(old_track != NULL){
    menu_layer_set_highlight_colors(s_layers[*old_track], GColorBlack, GColorWhite);
    layer_mark_dirty(menu_layer_get_layer(s_layers[*old_track]));
  }
}

static void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  int cur_trait = *((int *) data);
  int next_trait = cur_trait + 1;
  if( next_trait == NUM_TRAITS ){
    next_trait = 0;
  } 
  set_active_track(&next_trait, &cur_trait);
}

static void change_character_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  change_character();
}

MenuLayer* prep_track_layer(GPoint origin, int trait){
  Layer *window_layer = window_get_root_layer(s_window);
  GRect window_bounds = layer_get_bounds(window_layer);
  GSize size = { .w = window_bounds.size.w/4, .h = window_bounds.size.h - 2 * TITLE_HEIGHT };
  GRect bounds = { .origin = origin, .size = size};
  
  MenuLayer* layer =  menu_layer_create(bounds);
  menu_layer_set_callbacks(layer, &c_traits[trait], (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = NULL,
    .draw_header = NULL,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
    .select_long_click = change_character_callback,
    .get_cell_height = menu_get_cell_height_callback,
  });
  menu_layer_set_center_focused(layer, true);

  menu_layer_set_selected_index(layer, MenuIndex(0, get_track_index(s_current_char->default_index[trait])), MenuRowAlignNone, false);
  
  layer_add_child(window_layer, menu_layer_get_layer(layer));
  return layer;
}

void change_character(){
  int new_index = s_current_char_index + 1;
  if( new_index == NUM_CHARACTERS){
    new_index = 0;
  }
  s_current_char_index = new_index;
  s_current_char = characters[new_index];
  Layer *window_layer = window_get_root_layer(s_window);
  GRect window_bounds = layer_get_bounds(window_layer);
  GPoint moving_origin = { .x = window_bounds.origin.x , .y = window_bounds.origin.y + TITLE_HEIGHT };
  int16_t increment = window_bounds.size.w/4;
  
  for (int i = 0; i < NUM_TRAITS; i++) {
  s_layers[i] = prep_track_layer(moving_origin, i);
  moving_origin.x += increment;
  }
  set_active_track(&c_traits[MIGHT], NULL);
  
  GRect name_bounds = { .origin = { .x = window_bounds.origin.x, .y = window_bounds.size.h - TITLE_HEIGHT }, .size = { .w = window_bounds.size.w, .h = TITLE_HEIGHT}};
  s_name_layer = text_layer_create(name_bounds);
  text_layer_set_text(s_name_layer, s_current_char->name);
  text_layer_set_font(s_name_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
	text_layer_set_text_alignment(s_name_layer, GTextAlignmentCenter);
  text_layer_set_background_color(s_name_layer, s_current_char->background_color);
  text_layer_set_text_color(s_name_layer, s_current_char->text_color);
  layer_add_child(window_get_root_layer(s_window), text_layer_get_layer(s_name_layer));
  
  layer_remove_from_parent(bitmap_layer_get_layer(s_image_layer));
  layer_add_child(window_get_root_layer(s_window), bitmap_layer_get_layer(s_image_layer));
}

static void init(void) {
	// Create a window and get information about the window
	s_window = window_create();
  Layer *window_layer = window_get_root_layer(s_window);
  GRect window_bounds = layer_get_bounds(window_layer);
    
  s_font_bold = fonts_load_custom_font(
                          resource_get_handle(RESOURCE_ID_FGOTHIC_BOLD_24));
  s_font = fonts_load_custom_font(
                          resource_get_handle(RESOURCE_ID_FGOTHIC_24));
  s_image = gbitmap_create_with_resource(RESOURCE_ID_image);
  s_image_layer = bitmap_layer_create(window_bounds);
  bitmap_layer_set_bitmap(s_image_layer, s_image);
  bitmap_layer_set_compositing_mode(s_image_layer, GCompOpSet);
  change_character();
    
  layer_add_child(window_get_root_layer(s_window), bitmap_layer_get_layer(s_image_layer));
    
	window_stack_push(s_window, true);
  
	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

static void deinit(void) {
	// Destroy the text layer
  text_layer_destroy(s_name_layer);
  bitmap_layer_destroy(s_image_layer);
  gbitmap_destroy(s_image);
  for(int i = 0; i < NUM_TRAITS; i++){
    menu_layer_destroy(s_layers[i]);
  }
	
	// Destroy the window
	window_destroy(s_window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}
