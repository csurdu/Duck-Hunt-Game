#include "lab_m1/lab3/lab3.h"

#include <vector>
#include <iostream>

#include "lab_m1/lab3/transform2D.h"
#include "lab_m1/lab3/object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab3::Lab3()
{
}


Lab3::~Lab3()
{
}


float RandomFloat(float a, float b) {
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void Lab3::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    glm::vec3 cornersus1 = glm::vec3(1200, 650, 0);
    glm::vec3 cornersus2 = glm::vec3(1150, 650, 0);
    glm::vec3 cornersus3 = glm::vec3(1100, 650, 0);
    glm::vec3 cornersus4 = glm::vec3(1050, 650, 0);
    float squareSide = 100;

    // TODO(student): Compute coordinates of a square's center, and store
    // then in the `cx` and `cy` class variables (see the header). Use
    // `corner` and `squareSide`. These two class variables will be used
    // in the `Update()` function. Think about it, why do you need them?
    cx = corner.x + squareSide / 2;
    cy = corner.y + squareSide / 2;

    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateY = 0;

    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;

    // Initialize angularStep
    angularStep = 0;

    Mesh* glontgigant = object2D::CreateGloante("glontgigant", cornersus4, squareSide, glm::vec3(1, 0, 1));
    AddMeshToList(glontgigant);

    Mesh* glont1 = object2D::CreateGloante("glont1", cornersus1, squareSide, glm::vec3(1, 0, 0));
    AddMeshToList(glont1);
    Mesh* glont2 = object2D::CreateGloante("glont2", cornersus2, squareSide, glm::vec3(1, 0, 0));
    AddMeshToList(glont2);
    Mesh* glont3 = object2D::CreateGloante("glont3", cornersus3, squareSide, glm::vec3(1, 0, 0));
    AddMeshToList(glont3);






    Mesh* unu = object2D::CreatePunctajUpgrade("unu", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(unu);

    Mesh* doi = object2D::CreatePunctajUpgrade("doi", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(doi);

    Mesh* trei = object2D::CreatePunctajUpgrade("trei", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(trei);

    Mesh* patru = object2D::CreatePunctajUpgrade("patru", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(patru);

    Mesh* cinci = object2D::CreatePunctajUpgrade("cinci", corner, squareSide, glm::vec3(0, 1, 0));
    AddMeshToList(cinci);





    Mesh* pamant = object2D::CreatePamant("pamant", corner, squareSide, glm::vec3(0, 0.6, 0.2));
    AddMeshToList(pamant);
    Mesh* score = object2D::CreateScore("score", corner, squareSide, glm::vec3(0, 0.6, 0.2));
    AddMeshToList(score);


    Mesh* aripadreapta = object2D::CreateTriangle("aripadreapta", corner, squareSide, glm::vec3(0.6, 0.2, 0));
    AddMeshToList(aripadreapta);


    Mesh* aripastanga = object2D::CreateTriangle("aripastanga", corner, squareSide, glm::vec3(0.6, 0.2, 0));
    AddMeshToList(aripastanga);

    Mesh* viata1 = object2D::CreateCircle("viata1", corner, 30, glm::vec3(0.4, 0, 1));
    AddMeshToList(viata1);

    Mesh* viata2 = object2D::CreateCircle("viata2", corner, 30, glm::vec3(0.4, 0, 1));
    AddMeshToList(viata2);

    Mesh* viata3 = object2D::CreateCircle("viata3", corner, 30, glm::vec3(0.4, 0, 1));
    AddMeshToList(viata3);

    Mesh* corp = object2D::CreateTriangleBody("corp", corner, 70, glm::vec3(0.61, 0.29, 0));
    AddMeshToList(corp);
    Mesh* cap = object2D::CreateCircle("cap", corner, 30, glm::vec3(0.61, 0.29, 0));

    AddMeshToList(cap);

    Mesh* cioc = object2D::CreateCioc("cioc", corner, squareSide, glm::vec3(1, 0.2, 0));
    AddMeshToList(cioc);

}


void Lab3::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.6, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Lab3::Update(float deltaTimeSeconds)
{

    res_x = window->GetResolution().x;
    res_y = window->GetResolution().y;

    modelMatrix = glm::mat3(1);
    RenderMesh2D(meshes["pamant"], shaders["VertexColor"], modelMatrix);




    modelMatrix = glm::mat3(1);
    modelMatrix = modelMatrix * transform2D::Translate(res_x - 200, res_y - 150);
    RenderMesh2D(meshes["score"], shaders["VertexColor"], modelMatrix);




    rx = rx + 0.02;

    if (rx >= 0.5)
        rx = 0;
    if (aparitii >= 1.5 && final == 1 && gigant == 1)
    {
        exit(1);
    }


    if ((aparitii >= 1.8 && translateY >50) || (aparitii >= 1.8 && translateY < res_y-50))
    {

        translateX = 200;
        translateY = 0;
        aparitii = 0;
        teporizator_evadare = 0;
        ok1 = 0;
        alfa = RandomFloat(0.3, 0.8);
       // alfa = 0.4;
        dir = false;
        dir2 = false;
        viteza = viteza + 0.5;
      //  printf("UGHIUL SEF: %f\n", alfa);
    }
    else {
     //   printf("Unghi: %f\n", alfa);
       // printf("Aparitii: %f\n", aparitii);
      

        if (ok1 == 0) {
            if (teporizator_evadare <= 10) {
                teporizator_evadare = teporizator_evadare + deltaTimeSeconds;
                // printf("APARITII:%f\n", ok);
                if (dir == false) {
                    translateY += viteza * 400 * abs(deltaTimeSeconds * sin(alfa));


                }
                if (translateY >= res_y+100)
                {
                   // printf("ok\n");
                    alfa = 6.28 - alfa;

                    dir = true;

                }

                if (dir == true) {
                    translateY -= viteza * abs(400 * deltaTimeSeconds * sin(alfa));
                }
                if (translateY <= 0)
                {
                    dir = false;
                    alfa = 6.28 - alfa;
                   printf("ok\n");



                }
                if (dir2 == false) {
                    translateX += viteza * abs(400 * deltaTimeSeconds * cos(alfa));

                }
                if (translateX >= res_x+100)
                {
                    alfa = 3.14 - alfa;
                 //   printf("ok\n");
                    dir2 = true;

                }
                if (dir2 == true) {
                    translateX -= viteza * abs(400 * deltaTimeSeconds * cos(alfa));

                }
                if (translateX <= 100) {
                    dir2 = false;
                //    printf("ok\n");
                    alfa = 3.14 - alfa;


                }
            }

            else
            {

                translateY = translateY + 600 * deltaTimeSeconds;
                translateX = translateX;
                alfa = 3.14 / 2;
                vieti1 = vieti1 - 0.009;
                aparitii = aparitii + 0.01;
                aparitiiboss = aparitiiboss + 0.02;



            }


        }
        else
        {
            if (translateY > -300) {
                translateY = translateY - 300 * deltaTimeSeconds;
                translateX = translateX;
                alfa = -3.14 / 2;
                aparitii = aparitii + 0.01;
                aparitiiboss = aparitiiboss + 0.02;
            }


        }
    }
    //    printf("apaitii %f\n", aparitii);
    if (crestere_score > 0)
    {
        modelMatrix4 = glm::mat3(1);
        modelMatrix4 = modelMatrix4 * transform2D::Translate(res_x - 200, res_y - 150);
        RenderMesh2D(meshes["unu"], shaders["VertexColor"], modelMatrix4);
    }

    if (crestere_score > 1)

    {
        modelMatrix4 = glm::mat3(1);
        modelMatrix4 = modelMatrix4 * transform2D::Translate(res_x - 200, res_y - 150);
        RenderMesh2D(meshes["unu"], shaders["VertexColor"], modelMatrix4);
        modelMatrix3 = glm::mat3(1);
        modelMatrix3 = modelMatrix3 * transform2D::Translate(res_x - 175, res_y - 150);
        RenderMesh2D(meshes["doi"], shaders["VertexColor"], modelMatrix3);
    }

    if (crestere_score > 2)
    {
        modelMatrix4 = glm::mat3(1);
        modelMatrix4 = modelMatrix4 * transform2D::Translate(res_x - 200, res_y - 150);
        RenderMesh2D(meshes["unu"], shaders["VertexColor"], modelMatrix4);
        modelMatrix3 = glm::mat3(1);
        modelMatrix3 = modelMatrix3 * transform2D::Translate(res_x - 175, res_y - 150);
        RenderMesh2D(meshes["doi"], shaders["VertexColor"], modelMatrix3);
        modelMatrix2 = glm::mat3(1);
        modelMatrix2 = modelMatrix2 * transform2D::Translate(res_x - 150, res_y - 150);
        RenderMesh2D(meshes["trei"], shaders["VertexColor"], modelMatrix2);
    }
    if (crestere_score > 3)
    {
        modelMatrix4 = glm::mat3(1);
        modelMatrix4 = modelMatrix4 * transform2D::Translate(res_x - 200, res_y - 150);
        RenderMesh2D(meshes["unu"], shaders["VertexColor"], modelMatrix4);
        modelMatrix3 = glm::mat3(1);
        modelMatrix3 = modelMatrix3 * transform2D::Translate(res_x - 175, res_y - 150);
        RenderMesh2D(meshes["doi"], shaders["VertexColor"], modelMatrix3);
        modelMatrix2 = glm::mat3(1);
        modelMatrix2 = modelMatrix2 * transform2D::Translate(res_x - 150, res_y - 150);
        RenderMesh2D(meshes["trei"], shaders["VertexColor"], modelMatrix2);
        modelMatrix1 = glm::mat3(1);
        modelMatrix1 = modelMatrix1 * transform2D::Translate(res_x - 125, res_y - 150);
        RenderMesh2D(meshes["patru"], shaders["VertexColor"], modelMatrix1);
    }

    if (crestere_score > 4)
    {
        modelMatrix4 = glm::mat3(1);
        modelMatrix4 = modelMatrix4 * transform2D::Translate(res_x - 200, res_y - 150);
        RenderMesh2D(meshes["unu"], shaders["VertexColor"], modelMatrix4);
        modelMatrix3 = glm::mat3(1);
        modelMatrix3 = modelMatrix3 * transform2D::Translate(res_x - 175, res_y - 150);
        RenderMesh2D(meshes["doi"], shaders["VertexColor"], modelMatrix3);
        modelMatrix2 = glm::mat3(1);
        modelMatrix2 = modelMatrix2 * transform2D::Translate(res_x - 150, res_y - 150);
        RenderMesh2D(meshes["trei"], shaders["VertexColor"], modelMatrix2);
        modelMatrix1 = glm::mat3(1);
        modelMatrix1 = modelMatrix1 * transform2D::Translate(res_x - 125, res_y - 150);
        RenderMesh2D(meshes["patru"], shaders["VertexColor"], modelMatrix1);
        modelMatrix5 = glm::mat3(1);
        modelMatrix5 = modelMatrix5 * transform2D::Translate(res_x - 100, res_y - 150);
        RenderMesh2D(meshes["cinci"], shaders["VertexColor"], modelMatrix5);
    }


    // printf("TIMP SCORE %f\n", timp_score);


    if (gigant == 1) {
        // printf("CACAT");
        modelMatrix4 = glm::mat3(1);


        RenderMesh2D(meshes["glontgigant"], shaders["VertexColor"], modelMatrix4);



    }



    if (gloante > 2) {

        modelMatrix1 = glm::mat3(1);

        RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix1);


    }


    if (gloante > 1) {
        modelMatrix2 = glm::mat3(1);

        RenderMesh2D(meshes["glont2"], shaders["VertexColor"], modelMatrix2);


    }


    if (gloante > 0) {
        modelMatrix = glm::mat3(1);

        RenderMesh2D(meshes["glont3"], shaders["VertexColor"], modelMatrix);


    }
    if (gloante == 0)
    {
        gloante = 3;
        final = 1;
      //  exit(1);
    }
    //  printf("Viata:%f\n", vieti1);
    if (vieti1 > 2.3) {
        modelMatrix = glm::mat3(1);
        modelMatrix = modelMatrix * transform2D::Translate(50, res_y - 50);
        RenderMesh2D(meshes["viata1"], shaders["VertexColor"], modelMatrix);
    }

    if (vieti1 > 1) {
        modelMatrix = glm::mat3(1);
        modelMatrix = modelMatrix * transform2D::Translate(100, res_y - 50);
        RenderMesh2D(meshes["viata2"], shaders["VertexColor"], modelMatrix);

    }


    if (vieti1 > 0) {
        modelMatrix = glm::mat3(1);
        modelMatrix = modelMatrix * transform2D::Translate(150, res_y - 50);
        RenderMesh2D(meshes["viata3"], shaders["VertexColor"], modelMatrix);
    }

    if (aparitiiboss <= 20) {
           


        modelMatrix = glm::mat3(1);
        modelMatrix = modelMatrix


            * transform2D::Translate(-100, -100)
            * transform2D::Translate(translateX, translateY)
            * transform2D::Translate(50, 60)
            * transform2D::Rotate(alfa)
            * transform2D::Translate(-50, -60);

        RenderMesh2D(meshes["corp"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(initialx, initialy)
            * transform2D::Translate(0, 100)
            * transform2D::Rotate(RADIANS(270)));


        RenderMesh2D(meshes["cap"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(50 + initialx, 200 + initialy)
            * transform2D::Translate(100, 80));

        RenderMesh2D(meshes["cioc"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(50 + initialx, 200 + initialy)
            * transform2D::Translate(130, 60)
            * transform2D::Rotate(RADIANS(45)));

        RenderMesh2D(meshes["aripadreapta"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(initialx + 80, initialy + 80)
            * transform2D::Translate(60, 70)
            * transform2D::Rotate(RADIANS(230))
            * transform2D::Rotate(rx));


        RenderMesh2D(meshes["aripastanga"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(initialx + 20, initialy + 80)
            * transform2D::Translate(60, 80)

            * transform2D::Rotate(RADIANS(50))
            * transform2D::Rotate(rx));
    }
    else
    {
        viteza = 0.5;
        gigant = 1;

        Mesh* corp = object2D::CreateTriangleBody("corp", glm::vec3(0, 0, 0), 150, glm::vec3(0.61, 0.29, 0));
        AddMeshToList(corp);
        Mesh* cap = object2D::CreateCircle("cap", glm::vec3(0, 0, 0), 50, glm::vec3(0.61, 0.29, 0));

        AddMeshToList(cap);

        Mesh* cioc = object2D::CreateCioc("cioc", glm::vec3(0, 0, 0), 150, glm::vec3(1, 0.2, 0));
        AddMeshToList(cioc);

        Mesh* aripadrepta = object2D::CreateTriangle("aripadreapta", glm::vec3(0, 0, 0), 250, glm::vec3(1, 0.2, 0));
        AddMeshToList(aripadrepta);
        Mesh* aripastanga = object2D::CreateTriangle("aripastanga", glm::vec3(0, 0, 0), 250, glm::vec3(1, 0.2, 0));
        AddMeshToList(aripastanga);

        modelMatrix = glm::mat3(1);
        modelMatrix = modelMatrix

            * transform2D::Translate(50, 50)
            * transform2D::Translate(translateX, translateY)
            * transform2D::Translate(150, 60)
            * transform2D::Rotate(alfa)
            * transform2D::Translate(-150, -60);


        RenderMesh2D(meshes["corp"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(initialx, initialy)
            * transform2D::Translate(0, 100)
            * transform2D::Rotate(RADIANS(270)));


        RenderMesh2D(meshes["cap"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(50 + initialx, 200 + initialy)
            * transform2D::Translate(200, 50));

        RenderMesh2D(meshes["cioc"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(50 + initialx, 200 + initialy)
            * transform2D::Translate(240, 25)
            * transform2D::Rotate(RADIANS(45)));

        RenderMesh2D(meshes["aripadreapta"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(initialx + 80, initialy + 80)
            * transform2D::Translate(90, 25)
            * transform2D::Rotate(RADIANS(230))
            * transform2D::Rotate(rx));

        RenderMesh2D(meshes["aripastanga"], shaders["VertexColor"], modelMatrix //* transform2D::Translate(initialx + 20, initialy + 80)
            * transform2D::Translate(90, 75)

            * transform2D::Rotate(RADIANS(50))
            * transform2D::Rotate(rx));
    }



}


void Lab3::FrameEnd()
{

}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab3::OnInputUpdate(float deltaTime, int mods)
{
}


void Lab3::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Lab3::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}



void Lab3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    //printf("TranslateX:%f \n", translateX);
   // printf("TranslateY:%f \n", translateY);
   // printf("mouseX:%d \n", mouseX);
   // printf("mouseY:%d \n", mouseY);
    mouseY = res_y - mouseY;

    gloante = gloante - 1;
    if ((mouseX) < (translateX + 100) && (mouseX) > (translateX - 100) && (mouseY) > (translateY - 100) && (mouseY) < (translateY + 100))
    {
        // cout << "hit" << endl;
        ok1 = 1;
        crestere_score++;
        gloante = 3;
    }
    if (gigant == 1)
    {
        if ((mouseX) < (translateX + 200) && (mouseX) > (translateX - 200) && (mouseY) > (translateY - 200) && (mouseY) < (translateY + 200))
        {
            // cout << "hit" << endl;
            counter_boss++;
            if (counter_boss == 3) {
                ok1 = 1;
                
            }
            //  crestere_score++;

        }
    }

    // Add mouse button press event
}


void Lab3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab3::OnWindowResize(int width, int height)
{
}
