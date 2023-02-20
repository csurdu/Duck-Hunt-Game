#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Lab3 : public gfxc::SimpleScene
    {
     public:
        Lab3();
        ~Lab3();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        float cx, cy;
        float rx=0;
        float rx1 = 0;
        glm::mat3 modelMatrix;
        glm::mat3 modelMatrix1;
        glm::mat3 modelMatrix2;
        glm::mat3 modelMatrix3;
        glm::mat3 modelMatrix4;
        glm::mat3 modelMatrix5;
        glm::mat3 modelMatrix10;
        float translateX=0, translateY=0;
        float translateX1 = 0, translateY1 = 0;
        float scaleX, scaleY;
        float angularStep;
        float initialx=0, initialy=0;
        float mij_x = 0;
        float mij_y = 0;
        float var_rotatie;
        float alfa = 0.35;
        int counter_boss = 0;
            //float beta = 0.7;
            //float beta_max_x = 0.7;
        // TODO(student): If you need any other class variables, define them here.
        int res_x= window->GetResolution().x;
        int res_y = window->GetResolution().y;
        bool dir=false;
        bool dir2 = false;
        float teporizator_evadare = 0;
        int ok1 = 0;
        int gigant = 0;
        int gloante = 3;
        float vieti1 = 4;
        float vieti2 = 2;
        float vieti3 = 3;
        float aparitii = 0;
        float aparitiiboss = 0;
        float timp=0;
        float crestere_score=0;
        float viteza = 1;

        int final=0;
       
    };
}   // namespace m1
