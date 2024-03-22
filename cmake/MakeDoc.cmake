find_package(Doxygen)
if (DOXYGEN_FOUND)
#    set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
#    set(DOXYGEN_CLANG_DATABASE_PATH ${CMAKE_BINARY_DIR})
#    set(DOXYGEN_CLANG_OPTIONS -Wno-pragma-once-outside-header)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_STRIP_FROM_INC_PATH include)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/doc)
    set(DOXYGEN_HTML_EXTRA_STYLESHEET doxygen-awesome.css)
    set(DOXYGEN_DISABLE_INDEX NO)
    set(DOXYGEN_FULL_SIDEBAR NO)
    set(DOXYGEN_HTML_COLORSTYLE LIGHT)
    doxygen_add_docs(doc
            mainpage.md
            ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    add_custom_command(TARGET doc
            POST_BUILD
            WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}/latex
            COMMAND ${CMAKE_MAKE_PROGRAM} > /dev/null
            && ${CMAKE_COMMAND} -E copy
            ${DOXYGEN_OUTPUT_DIRECTORY}/latex/refman.pdf
            ${DOXYGEN_OUTPUT_DIRECTORY}/ASS-doc.pdf
            BYPRODUCTS ${DOXYGEN_OUTPUT_DIRECTORY}/ASS-doc.pdf
            VERBATIM
    )
else ()
    message(WARNING "Doxygen is necessary for docs")
endif ()
