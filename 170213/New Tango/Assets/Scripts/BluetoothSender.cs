using UnityEngine;
using System.Collections;
using UnityEngine.UI;

using TechTweaking.Bluetooth;

public class BluetoothSender : MonoBehaviour {

	private  BluetoothDevice device;
	public Text statusText;
	int counter = 10;
	public Text count;
	float timer = 0.1f;
	//public string[] toSend = new string[8];

	// Use this for initialization
	void Start () {
		BluetoothAdapter.enableBluetooth();//Force Enabling Bluetooth

		device = new BluetoothDevice();
		device.Name = "HC-06";

		/*
		 * 10 equals the char '\n' which is a "new Line" in Ascci representation, 
		 * so the read() method will retun a packet that was ended by the byte 10. simply read() will read lines.
		 * If you don't use the setEndByte() method, device.read() will return any available data (line or not), then you can order them as you want.
		 */
		device.setEndByte (10);


		/*
		 * The ManageConnection Coroutine will start when the device is ready for reading.
		 */
		device.ReadingCoroutine = ManageConnection;

	}

	public void connect() {
		statusText.text = "Status : ...";

		/*
		 * Notice that there're more than one connect() method, check out the docs to read about them.
		 * a simple device.connect() is equivalent to connect(10, 1000, false) which will make 10 connection attempts
		 * before failing completly, each attempt will cost at least 1 second.
		 * -----------
		 * To alter that  check out the following methods in the docs :
		 * connect (int attempts, int time, bool allowDiscovery) 
		 * normal_connect (bool isBrutal, bool isSecure)
		 */
		device.connect();
		//device.send (System.Text.Encoding.ASCII.GetBytes ("1"));//10 is our seperator Byte (sepration between packets)
	}

	public void disconnect() {
		device.close();
	}




	// Update is called once per frame
	public void Update () {
		if (timer <= 0.0f) {
			if (device != null) {
				//device.send ((byte)counter);
				//for (int i = 0; i < toSend.Length; i++) {
				//toSend [i] = (i * 25).ToString();
				//}

				device.send (System.Text.Encoding.ASCII.GetBytes ("s"));//10 is our seperator Byte (sepration between packets)
				for (int i = 0; i < 8; i++) {
					//device.send (System.Text.Encoding.ASCII.GetBytes ("1" + ","));//10 is our seperator Byte (sepration between packets)
					//device.send (System.Text.Encoding.ASCII.GetBytes (""));//10 is our seperator Byte (sepration between packets)
					//Debug.Log("THIS" + toSend[i].ToString());
					//Vibration test2 = GetComponent<Vibration> ();
					float test = GameObject.Find ("Tango Manager").GetComponent<Vibration> ().vibLevel [i];
					Debug.Log (test);
					if(test <= 0.5f){
						//GameObject.Find("BTConnector").GetComponent<BluetoothSender>().
						device.send (System.Text.Encoding.ASCII.GetBytes ("0"));//10 is our seperator Byte (sepration between packets)
					} else if(test <= 1.0f){
						//GameObject.Find("BTConnector").GetComponent<BluetoothSender>().
						device.send (System.Text.Encoding.ASCII.GetBytes ("1"));//10 is our seperator Byte (sepration between packets)
					} else if(test <= 1.5f){
						//GameObject.Find("BTConnector").GetComponent<BluetoothSender>().
						device.send (System.Text.Encoding.ASCII.GetBytes ("2"));//10 is our seperator Byte (sepration between packets)
					} else{
						//GameObject.Find("BTConnector").GetComponent<BluetoothSender>().
						device.send (System.Text.Encoding.ASCII.GetBytes ("4"));//10 is our seperator Byte (sepration between packets)
					}

					GameObject.Find ("Tango Manager").GetComponent<Vibration> ().vibLevel [i] = 0.0f;
					//device.send (System.Text.Encoding.ASCII.GetBytes (","));//10 is our seperator Byte (sepration between packets)

					//device.send (System.Text.Encoding.ASCII.GetBytes ("74" + ","));//10 is our seperator Byte (sepration between packets)
					//device.send (System.Text.Encoding.ASCII.GetBytes (""));//10 is our seperator Byte (sepration between packets)
				}

				device.send (System.Text.Encoding.ASCII.GetBytes ("t"));//10 is our seperator Byte (sepration between packets)
				for (int i = 0; i < 8; i++) {
					//device.send (System.Text.Encoding.ASCII.GetBytes ("1" + ","));//10 is our seperator Byte (sepration between packets)
					//device.send (System.Text.Encoding.ASCII.GetBytes (""));//10 is our seperator Byte (sepration between packets)
					//Debug.Log("THIS" + toSend[i].ToString());
					//Vibration test2 = GetComponent<Vibration> ();
					//float test = GameObject.Find ("Tango Manager").GetComponent<Vibration> ().vibLevel [i];
					//Debug.Log (test);

					device.send (System.Text.Encoding.ASCII.GetBytes (GameObject.Find ("Tango Manager").GetComponent<Vibration> ().vibHeight[i].ToString()));
					GameObject.Find ("Tango Manager").GetComponent<Vibration> ().vibHeight [i] = 0;
					//device.send (System.Text.Encoding.ASCII.GetBytes (","));//10 is our seperator Byte (sepration between packets)

					//device.send (System.Text.Encoding.ASCII.GetBytes ("74" + ","));//10 is our seperator Byte (sepration between packets)
					//device.send (System.Text.Encoding.ASCII.GetBytes (""));//10 is our seperator Byte (sepration between packets)
				}
			}
			timer = 0.1f;
		}
		timer -= Time.deltaTime;
	}

	//############### Reading Data  #####################
	//Please note that you don't have to use this Couroutienes/IEnumerator, you can just put your code in the Update() method
	IEnumerator  ManageConnection (BluetoothDevice device)
	{
		statusText.text = "Status : Connected & Can read";
		//if (device != null) {
		//device.send (System.Text.Encoding.ASCII.GetBytes ("1"));//10 is our seperator Byte (sepration between packets)
		//}

		while (device.IsReading) {
			if (device.IsDataAvailable) {
				byte [] msg = device.read ();//because we called setEndByte(10)..read will always return a packet excluding the last byte 10.

				if (msg != null && msg.Length > 0) {
					string content = System.Text.ASCIIEncoding.ASCII.GetString (msg);
					statusText.text = "MSG : " + content;
				}
			}

			yield return null;
		}

		statusText.text = "Status : Done Reading";
	}


}