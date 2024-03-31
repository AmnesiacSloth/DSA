
# Add library target
add_library(container_code
    arrayz/asVector.cpp
    linked_listz/asLinkedList.tpp) # might error unless implementation is here


# Unsure what this does ??
target_include_directories(container_code PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/arrayz
        ${CMAKE_CURRENT_SOURCE_DIR}/linked_listz
)

