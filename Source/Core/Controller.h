#pragma once

#include <QMouseEvent>
#include <QObject>
#include <QOpenGLFunctions>

namespace GlobeRenderer
{
    class EventHandler;
    class Renderer;
    class Window;

    class Controller : public QObject, protected QOpenGLFunctions
    {
        Q_OBJECT
      public:
        explicit Controller(QObject* parent = nullptr);
        ~Controller();

        void Run();

      public slots:
        void Initialize();
        void Resize(int w, int h);
        void Update(float ifps);
        void Render(float ifps);
        void KeyPressed(QKeyEvent*);
        void KeyReleased(QKeyEvent*);
        void MousePressed(QMouseEvent*);
        void MouseReleased(QMouseEvent*);
        void MouseMoved(QMouseEvent*);
        void WheelMoved(QWheelEvent*);

      private:
        Window* mWindow;
        Renderer* mRenderer;
        EventHandler* mEventHandler;

        float mDevicePixelRatio{1.0f};
        float mWidth{1600};
        float mHeight{900};
    };
}
