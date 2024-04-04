#include <configure.hpp>
#include <dlfcn.h>
#include <ASS/IGame.hpp>
#include <gtest/gtest.h>

TEST(TEST_SUITE_NAME, CanDlopen)
{
    void *handle = dlopen(SO_PATH, RTLD_GLOBAL | RTLD_NOW);
    ASSERT_NE(handle, nullptr) << dlerror();
    dlclose(handle);
}

TEST(TEST_SUITE_NAME, CanDlsym)
{

    void *handle = dlopen(SO_PATH, RTLD_GLOBAL | RTLD_NOW);
    void *fptr = dlsym(handle, "uwu_goofy_ahhh_game_entrypoint");
    ASSERT_NE(fptr, nullptr) << dlerror();
    dlclose(handle);
}
