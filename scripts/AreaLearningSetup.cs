using System.Collections;
using UnityEngine;
using Tango;

public class AreaLearningSetup : MonoBehaviour, ITangoLifecycle
{
	private TangoApplication m_tangoApplication;

	public void Start()
	{
		Debug.Log("Starting Tango Application... ");

		m_tangoApplication = FindObjectOfType<TangoApplication>();
		if (m_tangoApplication != null)
		{
			m_tangoApplication.Register(this);
			m_tangoApplication.RequestPermissions();

			Debug.Log("Granting Permissions... Passed. ");

		}
		if (m_tangoApplication == null) {
			Debug.Log("Granting Permissions... Failed. ");

		}
			

	}

	public void OnTangoPermissions(bool permissionsGranted)
	{
		if (permissionsGranted)
		{
			Debug.Log("Permission Accessed! ");

			AreaDescription[] list = AreaDescription.GetList();
			AreaDescription mostRecent = null;
			AreaDescription.Metadata mostRecentMetadata = null;

			if (list.Length > 0)
			{				
				Debug.Log("Searching for Files...");
				
				// Find and load the most recent Area Description
				mostRecent = list[0];
				mostRecentMetadata = mostRecent.GetMetadata();
				foreach (AreaDescription areaDescription in list)
				{
					AreaDescription.Metadata metadata = areaDescription.GetMetadata();
					if (metadata.m_dateTime > mostRecentMetadata.m_dateTime)
					{
						mostRecent = areaDescription;
						mostRecentMetadata = metadata;				
						Debug.Log("Loaded ADF File.");

					}
				}

				m_tangoApplication.Startup(mostRecent);

			}
			else
			{
				// Now, our application will load the most recent area description if present, or create a new area description if none exist on the device.
				m_tangoApplication.Startup(null);
				Debug.Log("No area descriptions available.");

			}
		}
	}

	public void OnTangoServiceConnected()
	{
	}

	public void OnTangoServiceDisconnected()
	{
	}
}