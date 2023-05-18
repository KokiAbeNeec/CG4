#pragma once

#include "Model.h"
#include "Camera.h"

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <d3dx12.h>
#include <DirectXMath.h>
#include <string>

class Object3d
{
protected: // �G�C���A�X
	// Microsoft::WRL::���ȗ�
	template <class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
public: // �T�u�N���X
	// �萔�o�b�t�@�p�f�[�^�\���́i���W�ϊ��s��p�j
	struct ConstBufferDataTransform
	{
		XMMATRIX viewproj;	// �r���[�v���W�F�N�V�����s��
		XMMATRIX world;		// ���[���h�s��
		XMFLOAT3 cameraPos;	// �J�������W�i���[���h���W�j
	};
public: // �ÓI�����o�֐�
	// setter
	static void SetDevise(ID3D12Device* devise) { Object3d::device = devise; }
	static void SetCamera(Camera* camera) { Object3d::camera = camera; }
	/// <summary>
	/// �O���t�B�b�N�p�C�v���C���̐���
	/// </summary>
	static void CreateGraphicsPipeline();
private: // �ÓI�����o�ϐ�
	// �f�o�C�X
	static ID3D12Device* device;
	// �J����
	static Camera* camera;
	// ���[�g�V�O�l�`��
	static ComPtr<ID3D12RootSignature> rootsignature;
	// �p�C�v���C���X�e�[�g�I�u�W�F�N�g
	static ComPtr<ID3D12PipelineState> pipelinestate;
public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initalize();
	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw(ID3D12GraphicsCommandList* cmdList);
	/// ���f���̃Z�b�g
	/// </summary>
	/// <param name="model">���f��</param>
	void SetModel(Model* model) { this->model = model; }
protected: // �����o�ϐ�
	// �萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuffTransform;
	// ���[�J���X�P�[��
	XMFLOAT3 scale = { 1,1,1 };
	// X,Y,Z�����̃��[�J����]�p
	XMFLOAT3 rotation = { 0,0,0 };
	// ���[�J�����W
	XMFLOAT3 position = { 0,0,0 };
	// ���[�J�����[���h�ϊ��s��
	XMMATRIX matWorld;
	//���f��
	Model* model = nullptr;
};