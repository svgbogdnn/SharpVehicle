#pragma once

// OpenGL Wrapper
#include <GL/Math/Mat4.hpp>

// Constants
#include <constants/constants.hpp>

// Forward declarations
#include <camera/camera_fwd.hpp>

// LibSmartCar
#include <transform/transform.hpp>

// Incomplete type resolve
#include <config/config_handler_fwd.hpp>

namespace App {

class Camera {
public:
    Camera(const GL::Vec3& position, const GL::Vec3& target, const float move_speed, const float rotate_speed,
        const float min_length_to_target, const float max_length_to_target, const bool is_target_fixed_on_car,
        const bool is_position_fixed_behind_car, const GL::Vec3& translation_from_car);
    Camera(const Config::CameraConfig& config);

    // To make the class polymorphic, so we are able
    // to use down-casting with shared_ptr
    virtual ~Camera() {}

    GL::Mat4 GetViewMatrix() const { return view_matrix_; }
    GL::Vec3 GetPosition() const { return position_; }

    void Move(const float delta_time);
    void UpdateWithModel(const GL::Mat4& model_matrix);
    bool ReachedFinalPosition() const { return reached_final_position_; }
    void UpdateMatrix();

protected:
    void MoveFront(const float delta_time);
    void MoveBack(const float delta_time);
    void MoveLeft(const float delta_time);
    void MoveRight(const float delta_time);

    void AlignStepFront(const float delta_coord);

    // The positive z-axis is going through your screen towards you
    GL::Vec3 position_;
    GL::Vec3 target_;
    GL::Vec3 reversed_direction_;

    float move_speed_;
    float rotate_speed_;

    // Not const, because may be updated with APP_CAMERA_RESERVE_WORLD_SPACE_UP value
    GL::Vec3 world_space_up_;

    GL::Vec3 right_;
    GL::Vec3 up_;

    GL::Mat4 view_matrix_;

    float cur_length_to_target_;
    float min_length_to_target_;
    float max_length_to_target_;

    Transform translation_from_car_;

    bool is_target_fixed_on_car_;
    bool is_position_fixed_behind_car_;
    bool reached_final_position_;

    friend class Context; // access to private variables
    friend class Gui; // access to private variables
};

} // namespace App
