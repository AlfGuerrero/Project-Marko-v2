using System.Collections;
using System.Collections.Generic;
using System.IO;
using Tango;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class testUIController :  MonoBehaviour, ITangoLifecycle
{

	/// <summary>
	/// ADF panel game object.
	/// 
	/// The panel selects the ADF file being used.
	/// </summary>
	public GameObject m_areaDescriptionPickerPanel;
	public GameObject m_TangoManager;
	public Text VibratorStatus;
	public Text HeightStatus;
	public Text DropOffStatus;

	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {

		VibratorStatus.text = "Vibrator Status: Front " + m_TangoManager.GetComponent<Vibration> ().vibLevel [0].ToString() + 
			", Front Right " + m_TangoManager.GetComponent<Vibration> ().vibLevel [1].ToString() + 
			", Right " + m_TangoManager.GetComponent<Vibration> ().vibLevel [2].ToString() + 
			", Back Right " + m_TangoManager.GetComponent<Vibration> ().vibLevel [3].ToString() + 
			", Back " + m_TangoManager.GetComponent<Vibration> ().vibLevel [4].ToString() + 
			", Back Left " + m_TangoManager.GetComponent<Vibration> ().vibLevel [5].ToString() + 
			", Left " + m_TangoManager.GetComponent<Vibration> ().vibLevel [6].ToString() + 
			", Front Left " + m_TangoManager.GetComponent<Vibration> ().vibLevel [7].ToString();

		HeightStatus.text = "Height Status: "; 

		DropOffStatus.text = "Drop Off Status: ";

		if (Input.GetKey(KeyCode.Escape))
		{
			Application.Quit();
		}
	}

	/// <summary>
	/// Internal callback when a permissions event happens.
	/// </summary>
	/// <param name="permissionsGranted">If set to <c>true</c> permissions granted.</param>
	public void OnTangoPermissions(bool permissionsGranted)
	{
		if (permissionsGranted)
		{
			Debug.Log ("Permissions Granted");
		}
		else
		{
			AndroidHelper.ShowAndroidToastMessage("Motion Tracking and Area Learning Permissions Needed");
			Application.Quit();
		}
	}

	/// <summary>
	/// This is called when successfully connected to the Tango service.
	/// </summary>
	public void OnTangoServiceConnected()
	{

	}

	/// <summary>
	/// This is called when disconnected from the Tango service.
	/// </summary>
	public void OnTangoServiceDisconnected()
	{
	}

	public void TriggerDropOff()
	{
		ResetVibrationValues ();
		AndroidHelper.ShowAndroidToastMessage("Pressed Drop Off.");
		int random = Random.Range (0, 7);
		int randomLeft = random - 1 ;
		int randomRight = random + 1;

		if (randomLeft < 0)
			randomLeft = 7;
		if (randomRight > 7)
			randomRight = 0;
		

		m_TangoManager.GetComponent<Vibration> ().vibLevel [random] = 0f;
		m_TangoManager.GetComponent<Vibration> ().vibLevel [randomLeft] = 0f;
		m_TangoManager.GetComponent<Vibration> ().vibLevel [randomRight] = 0f;

	}

	public void TriggerHeight()
	{
		AndroidHelper.ShowAndroidToastMessage("Pressed Height.");
	}

	public void TriggerDistance()
	{
		ResetVibrationValues ();
		AndroidHelper.ShowAndroidToastMessage("Pressed Distance.");
		m_TangoManager.GetComponent<Vibration> ().vibLevel [Random.Range(0,7)] = Random.Range(0f,5f);
	}

	public void ResetVibrationValues()
	{
		AndroidHelper.ShowAndroidToastMessage("Pressed Reset.");
		for(int i=0;i<8;i++){
			m_TangoManager.GetComponent<Vibration> ().vibLevel [i] = 6f;
		}
	}

	public void BackToADPPanel(){
		AndroidHelper.ShowAndroidToastMessage("Pressed Back.");
		gameObject.SetActive(false);
		m_areaDescriptionPickerPanel.SetActive(true);
	}
}
