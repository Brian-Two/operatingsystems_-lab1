# Operating Systems — Lab 1

My First C Program: Linked List implementation in C for CSCI-401.

- Sign up/log in to Codio with the course token and open Module 1.
- Implement the Linked List lab in C.
- Submit the GitHub repo URL in Canvas.

Instructor: Legand Burge (CSCI-401)

## Build and Run

- Build: `make`
- Run: `./list/list`

The Makefile compiles `list.c` and `main.c` and outputs the executable to `list/list` to avoid a name conflict with the `list/` directory.

## Testing

- `main.c` includes basic tests for:
  - list_add_to_front
  - list_remove_at_index (1-based)
  - list_get_elem_at (1-based)
  - list_get_index_of
  - list_add_to_back
  - list_add_at_index (inserts before given 1-based index)
  - list_remove_from_back / list_remove_from_front
  - list_is_in

Outputs are printed and simple string comparisons flag failures.
