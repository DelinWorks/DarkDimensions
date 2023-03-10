#ifndef __CUSTOM_UI_CONTAINER_H__
#define __CUSTOM_UI_CONTAINER_H__

#include "cocos2d.h"
#include "custom_ui.h"

#include "Helper/ChangeValue.h"
#include "Helper/short_types.h"
#include "Helper/Math.h"
#include "renderer/backend/Backend.h"

#include "shared_scenes/GameSingleton.h"
#include "shared_scenes/SoundGlobals.h"

#define ADVANCEDUI_P1_CAP_INSETS Rect(12, 12, 28 - 24, 28 - 24)
#define ADVANCEDUI_TEXTURE "9_slice_box_1.png"

namespace CustomUi
{
    class CustomUiContainer : public GUI {
    public:
        CustomUiContainer() {}
        static CustomUi::CustomUiContainer* create();

        // should be called every frame, it will update all ui elements to react if mouseLocationInView vector is inside that object on a specific camera and react on hover or hover leave
        bool update(cocos2d::Vec2 mouseLocationInView, cocos2d::Camera* cam);

        // should be called on onMouseDown or onTouchBegan, it will check on every element and react if mouseLocationInView vector is inside that object on a specific camera and perform a click action or defocus action if outside
        bool click(cocos2d::Vec2 mouseLocationInView, cocos2d::Camera* cam);

        void onEnable();
        void onDisable();
    };
}

#endif
