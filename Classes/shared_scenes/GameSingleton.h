#ifndef _GAMESINGLETON_H__
#define _GAMESINGLETON_H__

#include <string>
#include <vector>

#include "base/CCRef.h"
#include "cocos2d.h"
#include "Helper/short_types.h"

#include "string_manipulation_lib/base64.hpp"
#include "string_manipulation_lib/zlibString.hpp"
#include <thirdparty/glfw/include/GLFW/glfw3.h>

#include "shared_scenes/ProtectedTypes.hpp"

#include "script/LuaBindings.h"

struct GameConsole
{
    wchar_t* args;
    bool isConsole;
    bool isHeadless;
};

struct GameWindowDescriptor
{
    bool isFullscreen;
    bool isScreenSizeDirty;
    bool isCursorLockedToWindow;
    bool isAllowedToLeave;
    GLFWwindow* window;
    cocos2d::Rect lastKnownWindowRect;
    cocos2d::Size windowSize;
    i32 currentWindowCursor;
    ResolutionPolicy windowPolicy;
};

/** Game class responsible for global variables, client connections and save files */
class AX_DLL Darkness : public axmol::Ref
{
public:
    Darkness();
    ~Darkness();

    static Darkness* getInstance();

    void init();

    GameConsole console;

    GameWindowDescriptor gameWindow;

    void setupController();
    ax::Controller::KeyStatus getKeyState(ax::Controller::Key key);

    std::string server_path;

    std::wstring res_path;

    static void destroyInstance();
    static void restartInstance();
    
    lua_State* state = nullptr;

    /// <summary>
    /// anti-cheat variables
    /// </summary>

    std::thread modCheck;

    //

    uint64_t timeSinceStart = 0ULL;
    uint64_t currentTime = 0ULL;
    f32 elapsedGameTime = 0.0F;

    ////////////////////////////////////////////

    ProtectedType<i64> t;

    virtual void update(float delta);

    void setupLuaEngine();

    bool isAntiCheatReady = false;
    void initAntiCheat();
    void updateAntiCheat(float delta);
    void MessageBoxWin32(std::string caption, std::string text);
};

#endif